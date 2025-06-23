// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "IEnemigoComposite.h"
#include "Kismet/GameplayStatics.h"


void AEnemigo::ElegirNuevaDireccion()
{
    //Se crea un array con las direcciones adelante,detras,derecha e izquierda
    TArray<FVector> Direcciones;
    Direcciones.Add(FVector::ForwardVector);   // +X
    Direcciones.Add(-FVector::ForwardVector);  // -X
    Direcciones.Add(FVector::RightVector);     // +Y
    Direcciones.Add(-FVector::RightVector);    // -Y
    //
    int32 Index = FMath::RandRange(0, Direcciones.Num() - 1);
    CurrentDirection = Direcciones[Index];
    // Actualizar la rotación
    if (!CurrentDirection.IsNearlyZero())
    {
        FRotator NewRotation = CurrentDirection.Rotation();
        SetActorRotation(NewRotation);
    }
}
// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    //// Crear el componente de mesh
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(RootComponent); // Lo pegamos al capsule del Character

    // Cargar la malla
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(
        TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
    if (MeshAsset.Succeeded())
    {
        StaticMesh->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        StaticMesh->SetStaticMesh(MeshAsset.Object);
        StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -30.0f)); // Posición del mesh
        StaticMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f)); // Rotación del mesh
        StaticMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
    }

    // Dirección inicial al azar
    ElegirNuevaDireccion();

   
    //
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass(); // o tu clase propia si tenés una
    ////solo implemetamos esto /////////
    // Estas líneas hacen que el personaje rote hacia el objetivo
    GetCharacterMovement()->bUseControllerDesiredRotation = true;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    /////////

}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   
    //Si no estamos persiguiendo jugador, patrullar(movimiento básico)
    if (!bPersiguiendoJugador)
    {
        AddMovementInput(CurrentDirection, MoveSpeed);

        // Detectar obstáculos con raycast y cambiar dirección
        FHitResult Hit;
        FVector Start = GetActorLocation();
        FVector End = Start + CurrentDirection * 75.f;

        FCollisionQueryParams Params;
        Params.AddIgnoredActor(this);
        bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params);

        if (bHit)
        {
            ElegirNuevaDireccion();
        }

        // Debug línea para visualizar dirección
        DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 0.1f);
    }
}

// Called to bind functionality to input
void AEnemigo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemigo::Atacar()
{

    UE_LOG(LogTemp, Warning, TEXT("Enemigo individual ataca!"));

    APawn* Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!Jugador)
    {
        UE_LOG(LogTemp, Error, TEXT("No se encontro al jugador para perseguir."));
        return;
    }

    AAIController* AICon = Cast<AAIController>(GetController());
    if (!AICon)
    {
        UE_LOG(LogTemp, Error, TEXT("No se encontro AIController para este enemigo."));
        return;
    }

    // Ordena al AIController moverse hacia el jugador
    EPathFollowingRequestResult::Type Resultado = AICon->MoveToActor(Jugador, 5.0f);

    if (Resultado == EPathFollowingRequestResult::RequestSuccessful)
    {
        UE_LOG(LogTemp, Warning, TEXT("MoveToActor iniciado con exito"));
        bPersiguiendoJugador = true;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("MoveToActor fallo"));
    }
}

void AEnemigo::Mover(FVector Direccion)
{
}

void AEnemigo::Protegerse()
{
    UE_LOG(LogTemp, Warning, TEXT("Enemigos protegiendoce"));
}