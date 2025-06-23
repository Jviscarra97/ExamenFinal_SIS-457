// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LaberintoUno.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBuilderEscenario.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIBuilderEscenario : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API IIBuilderEscenario
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void ConstruirBloques() = 0;
	virtual void ConstruirMonedas() = 0;
	virtual void ConstruirPuertas() = 0;
	virtual void ConstruirEnemigos() = 0;
	virtual class ALaberintoUno* GetLaberinto() = 0;
};
