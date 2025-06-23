// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeLevel1.generated.h"

class AEnemigo;
class ABloque;

UCLASS()
class BOMBERMAN_012025_API AGameModeLevel1 : public AGameModeBase
{
	GENERATED_BODY()
public:
	AGameModeLevel1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  
	// alamacenar todo en un array
	UPROPERTY()
	TArray<ABloque*> TodosLosBloques;

	UPROPERTY()
	TArray<AEnemigo*> TodosLosEnemigos;
};
