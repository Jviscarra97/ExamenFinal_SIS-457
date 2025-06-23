// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueLadrillo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueLadrillo : public ABloque
{
	GENERATED_BODY()
public:
	ABloqueLadrillo();
	virtual void ComportamientoIndividual(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	bool bVisible = true;
	float TiempoAcumulado = 0.0f;
	float TiempoIntervalo = 3.0f; // Cambia cada 1 segundo (puedes ajustarlo)
};
