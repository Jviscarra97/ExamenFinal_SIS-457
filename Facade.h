// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaberintosFacade.h"
#include "Facade.generated.h"

UCLASS()
class BOMBERMAN_012025_API AFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// En Facade.h
	UPROPERTY()
	ALaberintosFacade* LaberintoActual = nullptr;
	//class ALaberintoUno* LaberintoUno = nullptr;
	void nivel1();
	void nivel2();
	void nivel3();
};
