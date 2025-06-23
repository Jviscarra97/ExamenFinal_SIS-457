// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaberintosFacade.generated.h"

UCLASS()
class BOMBERMAN_012025_API ALaberintosFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaberintosFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Facade Pattern
	class ADirector* Director;
	class ABuilderConcreto* Builder;

	virtual void LaberintoMaguico() PURE_VIRTUAL(ALaberintosFacade::LaberintoMaguico, );

	virtual void LaberintoVolador()PURE_VIRTUAL(ALaberintosFacade::LaberintoVolador, );

	void LaberintoBuilder();
};
