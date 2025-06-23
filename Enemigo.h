// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IEnemigoComposite.h"
#include "GameFramework/Character.h"
#include "Enemigo.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEnemigo : public ACharacter, public IIEnemigoComposite
{
	GENERATED_BODY()
	FVector CurrentDirection; // Dirección actual del enemigo

public:
	// Sets default values for this character's properties
	AEnemigo();
	
	bool bPersiguiendoJugador = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	UMaterialInterface* Material;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, Category = "Movimiento")
	///// estaba a 3 lo borraste ///jsjs
	float MoveSpeed = 2.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void ElegirNuevaDireccion();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Atacar() override;
	virtual void Mover(FVector Direccion) override;
	virtual void Protegerse() override;
};
