// Fill out your copyright notice in the Description page of Project Settings.


#include "PuertaTeletransportadora.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APuertaTeletransportadora::APuertaTeletransportadora()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Meash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Meash"));
	RootComponent = Meash;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);
	Trigger->SetBoxExtent(FVector(100.f, 100.f, 100.f));
	Trigger->SetCollisionProfileName(TEXT("Trigger"));

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &APuertaTeletransportadora::OnOverlapBegin);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloque(TEXT("StaticMesh'/Game/StarterContent/Props/SM_DoorFrame.SM_DoorFrame'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(
		TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
	if (ObjetoMallaBloque.Succeeded())
	{
		Meash->SetStaticMesh(ObjetoMallaBloque.Object);
		Meash->SetMaterial(0, MaterialBase.Object);
		//Meash->SetWorldScale3D(FVector(0.4f, 0.4f, 0.1f)); // X, Y, Z para las dimenciones 
	}
}

// Called when the game starts or when spawned
void APuertaTeletransportadora::BeginPlay()
{
	Super::BeginPlay();
	
	// Buscar todas las ventanas en el mundo
	TArray<AActor*> TodasLasVentanas;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APuertaTeletransportadora::StaticClass(), TodasLasVentanas);

	for (AActor* Actor : TodasLasVentanas)
	{
		APuertaTeletransportadora* OtraVentana = Cast<APuertaTeletransportadora>(Actor);
		if (OtraVentana && OtraVentana != this)
		{
			VentanasConectadas.Add(OtraVentana);
		}
	}
	// Iniciar alternancia de estado cada 10 segundos
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_CambioEstado, this, &APuertaTeletransportadora::AlternarEstadoVentana, 10.0f, true);
}

// Called every frame
void APuertaTeletransportadora::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuertaTeletransportadora::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// Verifica si la ventana est? activa
	if (!bVentanaActiva) return;
	ACharacter* OverlappingCharacter = Cast<ACharacter>(OtherActor);
	if (!OverlappingCharacter || VentanasConectadas.Num() == 0) return;

	float TiempoActual = GetWorld()->GetTimeSeconds();
	float* UltimoTiempo = UltimoTeletransporte.Find(OtherActor);

	if (UltimoTiempo && TiempoActual - *UltimoTiempo < TiempoCooldown)
	{
		// A?n est? en cooldown
		return;
	}

	// Elegimos una ventana aleatoria que no sea esta
	TArray<APuertaTeletransportadora*> VentanasValidas;
	for (APuertaTeletransportadora* Ventana : VentanasConectadas)
	{
		if (Ventana && Ventana != this)
		{
			VentanasValidas.Add(Ventana);
		}
	}

	if (VentanasValidas.Num() > 0)
	{
		int32 IndexAleatorio = FMath::RandRange(0, VentanasValidas.Num() - 1);
		APuertaTeletransportadora* Destino = VentanasValidas[IndexAleatorio];

		if (Destino)
		{
			UltimoTeletransporte.Add(OtherActor, TiempoActual); // Guardamos el tiempo del teletransporte
			OverlappingCharacter->SetActorLocation(Destino->GetActorLocation() + FVector(0.f, 0.f, 100.f));
		}
	}
}

void APuertaTeletransportadora::AlternarEstadoVentana()
{
	bVentanaActiva = !bVentanaActiva;

	// (opcional) Log para depuraci?n
	UE_LOG(LogTemp, Warning, TEXT("Ventana %s est? ahora %s"),
		*GetName(),
		bVentanaActiva ? TEXT("ACTIVA") : TEXT("INACTIVA"));
}
