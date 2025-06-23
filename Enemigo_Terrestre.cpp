// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Terrestre.h"
#include "IEnemigoComposite.h"

AEnemigo_Terrestre::AEnemigo_Terrestre() {

	/*auto Asset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));
	if (Asset.Object != nullptr) {

		Mesh->SetMaterial(0, Asset.Object);
	}*/

    // Crear el componente de mesh
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(RootComponent); // Lo pegamos al capsule del Character

    // Cargar la malla
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02'"));
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(
        TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
    if (MeshAsset.Succeeded())
    {
        StaticMesh->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        StaticMesh->SetStaticMesh(MeshAsset.Object);
        StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f)); // Posición del mesh
        StaticMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f)); // Rotación del mesh
        StaticMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
        StaticMesh->SetEnableGravity(false); // Evita que caiga
        StaticMesh->SetSimulatePhysics(false); // No física
    }
    // Altura base inicial
    AlturaBase = 0.f;
    TiempoFlotando = 0.f;
}
// Called when the game starts or when spawned
void AEnemigo_Terrestre::BeginPlay()
{
    Super::BeginPlay();
    AlturaBase = GetActorLocation().Z; // Guarda la Z inicial al comenzar
}

// Called every frame
void AEnemigo_Terrestre::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    TiempoFlotando += DeltaTime;

    float Amplitud = 100.f;      // Qué tan alto baja/sube
    float Velocidad = 2.f;      // Qué tan rápido sube/baja

    FVector PosicionActual = GetActorLocation();
    PosicionActual.Z = AlturaBase + FMath::Sin(TiempoFlotando * Velocidad) * Amplitud;

    SetActorLocation(PosicionActual);
}

// Called to bind functionality to input
void AEnemigo_Terrestre::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemigo_Terrestre::Atacar()
{
}

void AEnemigo_Terrestre::Mover(FVector Direccion)
{
}

void AEnemigo_Terrestre::Protegerse()
{
    UE_LOG(LogTemp, Warning, TEXT("Enemigos explocivos  proteganse"));
}