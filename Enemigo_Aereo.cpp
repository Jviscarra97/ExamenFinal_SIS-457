// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Aereo.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

AEnemigo_Aereo::AEnemigo_Aereo() {

	/*auto Asset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
	if (Asset.Object != nullptr) {

		mesh->SetMaterial(0, Asset.Object);
	}*/

    // Crear el componente de mesh
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(RootComponent); // Lo pegamos al capsule del Character

    // Cargar la malla
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Architecture/SM_AssetPlatform.SM_AssetPlatform'"));
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
}

// Called when the game starts or when spawned
void AEnemigo_Aereo::BeginPlay()
{
    Super::BeginPlay();

}

void AEnemigo_Aereo::ElegirNuevaDireccion()
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

// Called every frame
void AEnemigo_Aereo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //Si no estamos persiguiendo jugador, patrullar(movimiento básico)
    if (!moverse)
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
void AEnemigo_Aereo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemigo_Aereo::Atacar()
{
}

void AEnemigo_Aereo::Mover(FVector Direccion)
{
    moverse = false;
}

void AEnemigo_Aereo::Protegerse()
{
    UE_LOG(LogTemp, Warning, TEXT("Enemigos voladores protegance"));
}

