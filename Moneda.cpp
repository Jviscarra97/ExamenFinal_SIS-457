// Fill out your copyright notice in the Description page of Project Settings.


#include "Moneda.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Prototype.h"

// Sets default values
AMoneda::AMoneda()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Crear y configurar el componente de malla estatica
	Meash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Meash"));
	RootComponent = Meash;
	/////////////////////implementa  trigger para que se destroce las monedas////////////////////
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);
	Trigger->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	Trigger->SetCollisionProfileName(TEXT("OverlapAllDynamic")); // Importante para que detecte overlaps
	// Conectamos al evento de colisi?n
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AMoneda::OnOverlapBegin);
	//////////////////////////////////////////////
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallamoneda(
		TEXT("StaticMesh'/Game/StarterContent/Architecture/SM_AssetPlatform.SM_AssetPlatform'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(
		TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	if (ObjetoMallamoneda.Succeeded())
	{
		Meash->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0

		Meash->SetStaticMesh(ObjetoMallamoneda.Object);

		Meash->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		// Rotar la malla para que quede vertical
		Meash->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
		// Escalar el objeto (m?s peque?o)
		Meash->SetWorldScale3D(FVector(0.4f, 0.4f, 0.1f)); // X, Y, Z
	}

	// Inicializar valores por defecto
	velocidadRotacional = 30.0f; // grados por segundo
	anguloMaximoRotacion = 180.0f; // grados
	anguloActual = 0.0f;
	rotandoHaciaDerecha = true;
	ValorMoneda = 50; // Valor de la moneda, puedes cambiarlo si es necesario
}
//para el patron prototype, clon que devuelve un puntero a un objeto de tipo AActor (o derivado)///
AActor* AMoneda::clon() const
{

	FActorSpawnParameters SpawnParams;
	if (!GetWorld())
	{
		UE_LOG(LogTemp, Error, TEXT("GetWorld() es NULL en clon()"));
		return nullptr;
	}

	AMoneda* nueva = GetWorld()->SpawnActor<AMoneda>(GetClass(), GetActorLocation(), GetActorRotation(), SpawnParams);

	if (!nueva)
	{
		UE_LOG(LogTemp, Error, TEXT("Error al crear el clon de la Bloque"));
		return nullptr;
	}
	// Copiar propiedades importantes del original
	nueva->SetActorScale3D(GetActorScale3D());

	// Copiar transformaciones relativas del componente visual (Meash)
	nueva->Meash->SetRelativeRotation(Meash->GetRelativeRotation());
	nueva->Meash->SetRelativeLocation(Meash->GetRelativeLocation());
	nueva->Meash->SetWorldScale3D(Meash->GetComponentScale());
	// Copiar material si se cambió
	for (int32 i = 0; i < Meash->GetNumMaterials(); ++i)
	{
		UMaterialInterface* mat = Meash->GetMaterial(i);
		if (mat)
		{
			nueva->Meash->SetMaterial(i, mat);
		}
	}

	// Copiar variables personalizadas
	nueva->velocidadRotacional = velocidadRotacional;
	nueva->anguloMaximoRotacion = anguloMaximoRotacion;
	nueva->anguloActual = anguloActual;
	nueva->rotandoHaciaDerecha = rotandoHaciaDerecha;

	return Cast<AActor>(nueva);
}
//Hasta aqui el patron prototype, clon que devuelve un puntero a un objeto de tipo AActor (o derivado)///

// Called when the game starts or when spawned
void AMoneda::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoneda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Calcular cu?nto rotar este frame
	float rotacionFrame = velocidadRotacional * DeltaTime;

	// Cambiar direcci?n si excede el ?ngulo m?ximo
	if (rotandoHaciaDerecha)
	{
		anguloActual += rotacionFrame;
		if (anguloActual >= anguloMaximoRotacion)
		{
			rotandoHaciaDerecha = false;
		}
	}
	else
	{
		anguloActual -= rotacionFrame;
		if (anguloActual <= -anguloMaximoRotacion)
		{
			rotandoHaciaDerecha = true;
		}
	}

	// Aplicar rotaci?n al actor (eje Z por defecto) 
	// Puedes cambiar NuevaRotacion.Yaw por Pitch o Roll si deseas rotar en otro eje.
	FRotator NuevaRotacion = GetActorRotation();
	NuevaRotacion.Yaw += rotandoHaciaDerecha ? rotacionFrame : -rotacionFrame;
	SetActorRotation(NuevaRotacion);
}

//funcion que desace las monedas con un destoy y muestra el puntaje//
void AMoneda::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		// Comprobamos si el actor que toca es el jugador (puedes usar tags o clases espec?ficas tambi?n)
		ACharacter* PlayerChar = Cast<ACharacter>(OtherActor);
		if (PlayerChar)
		{
			// Mensaje en pantalla
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("?50 monedas recibidas!"));
			}

			// Destruir moneda
			Destroy();
		}
	}
}