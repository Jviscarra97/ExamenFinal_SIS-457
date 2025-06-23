// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBloquePastoState.h"
#include "EstadoVerde.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEstadoVerde : public AActor, public IIBloquePastoState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoVerde();
	virtual void EjecutarEstado_Implementation(class ABloquePasto* BloquePasto) override;
	virtual FString ObtenerNombreEstado_Implementation() const override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	
};
