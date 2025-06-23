// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuertaTeletransportadora.generated.h"

UCLASS(Blueprintable, BlueprintType)
class BOMBERMAN_012025_API APuertaTeletransportadora : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuertaTeletransportadora();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* Meash;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	class UBoxComponent* Trigger;

	// Ventanas conectadas para teletransportaci?n
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleport")
	TArray<APuertaTeletransportadora*> VentanasConectadas;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
private:
	UPROPERTY()
	TMap<AActor*, float> UltimoTeletransporte;

	UPROPERTY(EditAnywhere, Category = "Teleport")
	float TiempoCooldown = 1.0f; // 1 segundo 
private:
	// Alterna el estado de la ventana
	bool bVentanaActiva = true;

	FTimerHandle TimerHandle_CambioEstado;

	// Cambia el estado activo/inactivo
	void AlternarEstadoVentana();
};
