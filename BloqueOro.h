// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueOro.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueOro : public ABloque
{
	GENERATED_BODY()
	
public:
	ABloqueOro();
	virtual void ComportamientoIndividual(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
private:
	// Variables para que el bloque de oro se escale y destruya
	float TiempoDestruccion = 0.0f; // Tiempo acumulado para la destrucción
	float TiempoMaximoDestruccion = 3.0f; // Tiempo máximo antes de destruir el bloque
	
	
};
