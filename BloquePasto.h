// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloquePasto.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloquePasto : public ABloque
{
	GENERATED_BODY()
public:
	ABloquePasto();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	/*void CambiarEstado(IIBloquePastoState* NuevoEstado);
	void EjecutarEstado();

private:
	UPROPERTY()
	IIBloquePastoState* EstadoActual;*/

	void CambiarEstado(AActor* NuevoEstado);
	void EjecutarEstado();

private:
	UPROPERTY()
	AActor* EstadoActual; // Debe implementar IIBloquePastoState
	
	// Materiales para los diferentes estados del bloque
	UPROPERTY(EditDefaultsOnly, Category = "Materiales")
	UMaterialInterface* MaterialVerde;

	UPROPERTY(EditDefaultsOnly, Category = "Materiales")
	UMaterialInterface* MaterialQuemado;


public:
	AActor* ObtenerEstadoActual() const;

public:
	void AplicarMaterialEstado(FString NombreEstado);

};
