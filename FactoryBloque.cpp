// Fill out your copyright notice in the Description page of Project Settings.


#include "FactoryBloque.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueLadrillo.h"
#include "BloqueVidrio.h"
#include "BloqueMadera.h"
#include "BloqueOro.h"

// Sets default values
AFactoryBloque::AFactoryBloque()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFactoryBloque::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFactoryBloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// funcion para crear un bloque de un tipo especifico y en una posicion especifica
ABloque* AFactoryBloque::CrearBloque(FString tipoBloque, FVector posicion)
{

    // Crear un nuevo bloque
    if (tipoBloque.Equals("Acero")) {
        return GetWorld()->SpawnActor<ABloqueAcero>
			(ABloqueAcero::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f)); // spawn actor para crear un bloque de acero
    }
    else if (tipoBloque.Equals("Ladrillo")) {
        return GetWorld()->SpawnActor<ABloqueLadrillo>
			(ABloqueLadrillo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f)); // spawn actor para crear un bloque de ladrillo
    }
    else if (tipoBloque.Equals("Madera")) {
        return GetWorld()->SpawnActor<ABloqueMadera>
			(ABloqueMadera::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f)); // spawn actor para crear un bloque de madera
    }
    else if (tipoBloque.Equals("Vidrio")) {
        return GetWorld()->SpawnActor<ABloqueVidrio>
			(ABloqueVidrio::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f)); // spawn actor para crear un bloque de vidrio
    }
    else if (tipoBloque.Equals("Oro")) {
        return GetWorld()->SpawnActor<ABloqueOro>
			(ABloqueOro::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f)); // spawn actor para crear un bloque de oro

    }
    else return nullptr; ; //Return null if the string isn't valid
}


