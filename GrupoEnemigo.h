// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEnemigoComposite.h"
#include "GrupoEnemigo.generated.h"

UCLASS()
class BOMBERMAN_012025_API AGrupoEnemigo : public AActor, public IIEnemigoComposite
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrupoEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Atacar() override;
	virtual void Mover(FVector Direccion) override;
	virtual void Protegerse() override;
	void AgregarEnemigo(TScriptInterface<IIEnemigoComposite> NuevoEnemigo);
private:
	UPROPERTY()
	TArray<TScriptInterface<IIEnemigoComposite>> Enemigos;
};
