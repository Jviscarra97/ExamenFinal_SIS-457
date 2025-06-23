// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBloquePastoState.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIBloquePastoState : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API IIBloquePastoState
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Este método lo llamará el contexto para que el estado actúe
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Estado")
	void EjecutarEstado(class ABloquePasto* BloquePasto);

	// Devuelve el nombre del estado actual (opcional, útil para debug)
	// El debug es una parte importante del desarrollo de videojuegos, ya que permite identificar y solucionar problemas de manera más eficiente.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Estado")
	FString ObtenerNombreEstado() const;

};
