// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLadrillo.h"
ABloqueLadrillo::ABloqueLadrillo() {
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
	if (AssetMaterial.Object) {

		Mesh->SetMaterial(0, AssetMaterial.Object);
	}



}
void ABloqueLadrillo::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABloqueLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	////para que los bloques desaparescan y aprarescan///
	ComportamientoIndividual(DeltaTime);
}

void ABloqueLadrillo::ComportamientoIndividual(float DeltaTime)
{
	TiempoAcumulado += DeltaTime;

	if (TiempoAcumulado >= TiempoIntervalo)
	{
		// Cambiar visibilidad
		bVisible = !bVisible;

		SetActorHiddenInGame(!bVisible); // true oculta, false muestra

		// Reiniciar el tiempo
		TiempoAcumulado = 0.0f;
	}
}
