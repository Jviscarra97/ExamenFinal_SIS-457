// Fill out your copyright notice in the Description page of Project Settings.


#include "GrupoEnemigo.h"
#include "Enemigo.h"

// Sets default values
AGrupoEnemigo::AGrupoEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrupoEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrupoEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrupoEnemigo::Atacar()
{
    for (auto& Enemigo : Enemigos)
    {
        if (Enemigo)
        {
            Enemigo->Atacar();
        }
    }
}

void AGrupoEnemigo::Mover(FVector Direccion)
{
    for (auto& Enemigo : Enemigos)
    {
        if (Enemigo)
        {
            Enemigo->Mover(Direccion);
        }
    }
}

void AGrupoEnemigo::Protegerse()
{

    for (auto& Enemigo : Enemigos)
    {
        if (Enemigo)
        {
            Enemigo->Protegerse();
        }
    }
}

void AGrupoEnemigo::AgregarEnemigo(TScriptInterface<IIEnemigoComposite> NuevoEnemigo)
{
    if (NuevoEnemigo)
    {
        Enemigos.Add(NuevoEnemigo);
    }
}