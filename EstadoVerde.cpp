// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoVerde.h"
#include "BloquePasto.h"
#include "EstadoQuemado.h"

// Sets default values
AEstadoVerde::AEstadoVerde()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoVerde::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoVerde::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoVerde::EjecutarEstado_Implementation(ABloquePasto* BloquePasto)
{
	// Simula que detecta fuego cercano
	bool HayFuego = true;

	if (HayFuego)
	{
		// Cambia al estado quemado
		if (UWorld* World = BloquePasto->GetWorld())
		{
			AEstadoQuemado* NuevoEstado = World->SpawnActor<AEstadoQuemado>();
			BloquePasto->CambiarEstado(NuevoEstado);
			Destroy(); // Destruye este estado (opcional)
		}
	}
}
FString AEstadoVerde::ObtenerNombreEstado_Implementation() const
{
	return TEXT("EstadoVerde");
}