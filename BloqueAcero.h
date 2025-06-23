// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueAcero.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueAcero : public ABloque
{
	GENERATED_BODY()

public:

	ABloqueAcero();

	virtual void ComportamientoIndividual(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;
private:
 
	// Variables privadas para el comportamiento del bloque de acero
	FRotator RotacionInicialAcero;
	FRotator RotacionObjetivoAcero;
	bool bGirandoHaciaAdelanteAcero = true;
	float VelocidadRotacionAcero = 180.f; // grados por segundo
};
