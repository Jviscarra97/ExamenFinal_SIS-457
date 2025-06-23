// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueOro.h"

ABloqueOro::ABloqueOro() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}

void ABloqueOro::ComportamientoIndividual(float DeltaTime)
{
	// Comportamiento único del bloque de oro: destruir y reaparecer después de un tiempo
	TiempoDestruccion += DeltaTime; // Acumular tiempo de destrucción
	if (TiempoDestruccion >= TiempoMaximoDestruccion) {
		// Destruir el bloque después de un tiempo máximo
		Destroy();
		return;
	}
	
}

void ABloqueOro::BeginPlay()
{
	Super::BeginPlay();
	TiempoDestruccion = 0.0f; // Reiniciar el tiempo de destrucción
}

void ABloqueOro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Comportamiento único del bloque de oro
	ComportamientoIndividual(DeltaTime);
}
