// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LaberintoUno.h"
#include "IBuilderEscenario.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderConcreto.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABuilderConcreto : public AActor, public IIBuilderEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderConcreto();
	class ALaberintoUno* Laberinto;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	
	virtual void Tick(float DeltaTime) override;
	virtual void ConstruirBloques() override;
	virtual void ConstruirMonedas()  override;
	virtual void ConstruirPuertas() override;
	virtual void ConstruirEnemigos() override;
	virtual  ALaberintoUno* GetLaberinto() override;
	FVector UbicacionInicial;
};
