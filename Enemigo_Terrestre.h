// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "IEnemigoComposite.h"
#include "Enemigo_Terrestre.generated.h"


/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigo_Terrestre : public ACharacter, public IIEnemigoComposite
{
	GENERATED_BODY()

public:

	AEnemigo_Terrestre();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	UMaterialInterface* Material;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	// Para movimiento senoidal
	float AlturaBase;
	float TiempoFlotando;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Atacar() override;
	virtual void Mover(FVector Direccion) override;
	virtual void Protegerse() override;
};
