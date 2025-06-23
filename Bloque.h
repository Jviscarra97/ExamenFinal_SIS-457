// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABloque : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloque();
	
	//Posicion inicial del bloque al comenzar el juego
	FVector PosicionInicial;

	//virtual AActor* clon() const override;

	//control de moviento del bloque
	int TipoMovimiento;		//0 = no se mueve, 1 = se mueve de un punto a otro, 2 = se mueve en un bucle entre dos puntos
	float FloatSpeed;		// velocidad de movimiento del bloque
	bool bPuedeMoverse;	// si el bloque puede moverse o no
	float RotationSpeed; // Velocidad de rotación del bloque

	//Direccion para alternar cuando llegue a los extremos
	int DireccionMovimientoX;
	int DireccionMovimientoY;
	int DireccionMovimientoZ;

	int32 IDBloque; // ID del bloque para identificarlo en el juego

	virtual void ComportamientoIndividual(float DetaTime);
	virtual void ComportamientoGrupal();
	
	UPROPERTY()
	UStaticMeshComponent* Mesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

private:
	
	FVector PosInicial;
	FVector PosFinal;
	float TiempoDeMovimiento;
	float TiempoTranscurrido;

public:

	/*void IniciarMovimiento(FVector NuevaPosObjetivo, float Tiempo);
	void MoverBloque(float DeltaTime);*/

};
