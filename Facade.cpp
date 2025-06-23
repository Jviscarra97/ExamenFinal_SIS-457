// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"
#include "LaberintosFacade.h"
#include "LaberintoUno.h"

// Sets default values
AFacade::AFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFacade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//Funciones para el laberinto facade
void AFacade::nivel1()
{
    if (!LaberintoActual)
    {
        LaberintoActual = GetWorld()->SpawnActor<ALaberintoUno>(ALaberintoUno::StaticClass());
    }

    ALaberintoUno* LaberintoUno = Cast<ALaberintoUno>(LaberintoActual);
    if (LaberintoUno)
    {
        UE_LOG(LogTemp, Warning, TEXT("Ejecutando LaberintoMaguico"));
        LaberintoUno->LaberintoMaguico();
    }
}

void AFacade::nivel2()
{
    if (!LaberintoActual)
    {
        LaberintoActual = GetWorld()->SpawnActor<ALaberintoUno>(ALaberintoUno::StaticClass());
    }

    ALaberintoUno* LaberintoUno = Cast<ALaberintoUno>(LaberintoActual);
    if (LaberintoUno)
    {
        UE_LOG(LogTemp, Warning, TEXT("Ejecutando LaberintoVolador"));
        LaberintoUno->LaberintoVolador();
    }
}

void AFacade::nivel3()
{
    if (!LaberintoActual)
    {
        // Aquí puedes instanciar directamente la clase concreta (como ALaberintoUno)
        LaberintoActual = GetWorld()->SpawnActor<ALaberintoUno>(ALaberintoUno::StaticClass());
    }

    if (LaberintoActual)
    {
        LaberintoActual->LaberintoBuilder();
    }
}
