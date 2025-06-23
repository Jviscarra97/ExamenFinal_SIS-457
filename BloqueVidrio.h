// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueVidrio.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueVidrio : public ABloque
{
	GENERATED_BODY()
public:
	ABloqueVidrio();
	virtual void ComportamientoIndividual(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	FVector EscalaInicial;
	FVector EscalaMaxima;
	bool bEscalandoAumentando = true;
	float VelocidadEscalado = 1.5f;
};
