// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"
#include "LaberintoUno.h"

// Sets default values
ADirector::ADirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// Patron builder
void ADirector::LlamarConstructor(AActor* _Constructor)
{
	ConstructorEscenario = Cast<IIBuilderEscenario>(_Constructor);
}
///llama a cada builder para que construlla lo que el director le pida///
void ADirector::ConstruirLaberinto()
{
	ConstructorEscenario->ConstruirBloques();
	ConstructorEscenario->ConstruirMonedas();
	ConstructorEscenario->ConstruirPuertas();
	ConstructorEscenario->ConstruirEnemigos();
}

void ADirector::Modificacion()
{
}

ALaberintoUno* ADirector::GetLaberinto()
{
	if (ConstructorEscenario)
	{
		return ConstructorEscenario->GetLaberinto();
	}
	return nullptr;
}