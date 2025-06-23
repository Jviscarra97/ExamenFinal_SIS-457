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

	if (bGirandoHaciaAdelanteAcero) // Si el bloque de acero est� girando hacia adelante
    {
        // Interpolaci�n constante hacia la rotaci�n objetivo
        RotActualm = FMath::RInterpConstantTo(RotActualm, RotacionObjetivoAcero, DeltaTime, VelocidadRotacionAcero); 
		SetActorRotation(RotActualm); // Aplicamos la rotaci�n al actor

		if (RotActualm.Equals(RotacionObjetivoAcero, 1.0f)) // Si la rotaci�n actual es igual a la rotaci�n objetivo
        {
			bGirandoHaciaAdelanteAcero = false; // Cambiamos la direcci�n del giro a hacia atr�s
        }
    }
	else // Si el bloque de acero est� girando hacia atr�s
    {
		RotActualm = FMath::RInterpConstantTo(RotActualm, RotacionInicialAcero, DeltaTime, VelocidadRotacionAcero); // Interpolaci�n constante hacia la rotaci�n inicial
		SetActorRotation(RotActualm); // Aplicamos la rotaci�n al actor

		if (RotActualm.Equals(RotacionInicialAcero, 1.0f)) // Si la rotaci�n actual es igual a la rotaci�n inicial
        {
			bGirandoHaciaAdelanteAcero = true; // Cambiamos la direcci�n del giro a hacia adelante
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