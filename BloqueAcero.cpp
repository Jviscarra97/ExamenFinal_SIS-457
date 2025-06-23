// Fill out your copyright notice in the Description page of Project Settings.

#include "BloqueAcero.h"

ABloqueAcero::ABloqueAcero()
{
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Steel.M_Metal_Steel'"));
	if (AssetMaterial.Object != nullptr) {
		Mesh->SetMaterial(0, AssetMaterial.Object);
	}
}

void ABloqueAcero::ComportamientoIndividual(float DeltaTime)
{
	FRotator RotActualm = GetActorRotation(); // Rotacion actual del bloque de acero

	if (bGirandoHaciaAdelanteAcero) // Si el bloque de acero está girando hacia adelante
    {
        // Interpolación constante hacia la rotación objetivo
        RotActualm = FMath::RInterpConstantTo(RotActualm, RotacionObjetivoAcero, DeltaTime, VelocidadRotacionAcero); 
		SetActorRotation(RotActualm); // Aplicamos la rotación al actor

		if (RotActualm.Equals(RotacionObjetivoAcero, 1.0f)) // Si la rotación actual es igual a la rotación objetivo
        {
			bGirandoHaciaAdelanteAcero = false; // Cambiamos la dirección del giro a hacia atrás
        }
    }
	else // Si el bloque de acero está girando hacia atrás
    {
		RotActualm = FMath::RInterpConstantTo(RotActualm, RotacionInicialAcero, DeltaTime, VelocidadRotacionAcero); // Interpolación constante hacia la rotación inicial
		SetActorRotation(RotActualm); // Aplicamos la rotación al actor

		if (RotActualm.Equals(RotacionInicialAcero, 1.0f)) // Si la rotación actual es igual a la rotación inicial
        {
			bGirandoHaciaAdelanteAcero = true; // Cambiamos la dirección del giro a hacia adelante
        }
    }


}

void ABloqueAcero::BeginPlay()
{
    Super::BeginPlay();
	RotacionInicialAcero = GetActorRotation(); // Guardamos la rotacion inicial del bloque de acero
	RotacionObjetivoAcero = RotacionInicialAcero + FRotator(0.f, 180.f, 0.f); // Definimos la rotacion objetivo a 180 grados en el eje Y
}

// Called every frame
void ABloqueAcero::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ////para activar su movimiento unico a cada blouqeAcero///
    ComportamientoIndividual(DeltaTime); 
}