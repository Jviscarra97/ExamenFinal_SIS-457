// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderConcreto.h"
#include "Bloque.h"
#include "BloqueBurbuja.h"
#include "BloqueConcreto.h"
#include "BloqueCuarzo.h"
#include "BloqueHielo.h"
#include "Enemigo.h"
#include "PuertaTeletransportadora.h"
#include "Moneda.h"

// Sets default values
ABuilderConcreto::ABuilderConcreto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	///// para la ubicacion  de donde se contrulle todo////
	UbicacionInicial = FVector(-3994.488813, -3997.341838, 0.0f);
}

// Called when the game starts or when spawned
void ABuilderConcreto::BeginPlay()
{
	Super::BeginPlay();
	Laberinto = GetWorld()->SpawnActor<ALaberintoUno>(ALaberintoUno::StaticClass());
}

// Called every frame
void ABuilderConcreto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderConcreto::ConstruirBloques()
{
	ABloque* Bloque = nullptr;
	for (int fila = 0; fila < Laberinto->MapaLaberinto.Num(); fila++) {
		for (int columna = 0; columna < Laberinto->MapaLaberinto[fila].Num(); columna++) {
			int valor = Laberinto->MapaLaberinto[fila][columna];
			FVector Posicion_Actual = UbicacionInicial + FVector(fila * 400.0f, columna * 400.0f, 0.0f);
			if (valor == 1) {
				Bloque = GetWorld()->SpawnActor<ABloqueBurbuja>(ABloqueBurbuja::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
			if (valor == 2) {
				Bloque = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
			if (valor == 3) {
				Bloque = GetWorld()->SpawnActor<ABloqueCuarzo>(ABloqueCuarzo::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
			if (valor == 4) {
				Bloque = GetWorld()->SpawnActor<ABloqueHielo>(ABloqueHielo::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
			if (Bloque) {
				Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 4.0f));
			}
		}
	}
}

void ABuilderConcreto::ConstruirMonedas()
{
	for (int fila = 0; fila < Laberinto->MapaLaberinto.Num(); fila++) {
		for (int columna = 0; columna < Laberinto->MapaLaberinto[fila].Num(); columna++) {
			int valor = Laberinto->MapaLaberinto[fila][columna];
			FVector Posicion_Actual = UbicacionInicial + FVector(fila * 400.0f, columna * 400.0f, 200.0f);
			if (valor == 5) {
				GetWorld()->SpawnActor<AMoneda>(AMoneda::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
		}
	}
}

void ABuilderConcreto::ConstruirPuertas()
{
	for (int fila = 0; fila < Laberinto->MapaLaberinto.Num(); fila++) {
		for (int columna = 0; columna < Laberinto->MapaLaberinto[fila].Num(); columna++) {
			int valor = Laberinto->MapaLaberinto[fila][columna];
			FVector Posicion_Actual = UbicacionInicial + FVector(fila * 400.0f, columna * 400.0f, 180.0f);
			if (valor == 6) {
				GetWorld()->SpawnActor<APuertaTeletransportadora>(APuertaTeletransportadora::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
		}
	}
}

void ABuilderConcreto::ConstruirEnemigos()
{
	for (int fila = 0; fila < Laberinto->MapaLaberinto.Num(); fila++) {
		for (int columna = 0; columna < Laberinto->MapaLaberinto[fila].Num(); columna++) {
			int valor = Laberinto->MapaLaberinto[fila][columna];
			FVector Posicion_Actual = UbicacionInicial + FVector(fila * 400.0f, columna * 400.0f, 180.0f);
			if (valor == 7) {
				GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
		}
	}
}

ALaberintoUno* ABuilderConcreto::GetLaberinto()
{
	return Laberinto;
}
