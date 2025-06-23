// Fill out your copyright notice in the Description page of Project Settings.


#include "LaberintoUno.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueLadrillo.h"
#include "BloqueVidrio.h"
#include "BloqueMadera.h"
#include "Components/SceneComponent.h"

// Sets default values
ALaberintoUno::ALaberintoUno()
{

	LaberintoRoot = CreateDefaultSubobject<USceneComponent>(TEXT("LaberintoRoot"));
	RootComponent = LaberintoRoot;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALaberintoUno::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaberintoUno::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Movimiento de vuelo (sube y baja)
	if (bVolando)
	{
		FVector PosActual = LaberintoRoot->GetRelativeLocation();

		if (bSubiendo)
		{
			PosActual.Z += VelocidadSubida * DeltaTime;

			if (PosActual.Z >= AlturaObjetivo)
			{
				PosActual.Z = AlturaObjetivo;
				bSubiendo = false; // empieza a bajar
			}
		}
		else
		{
			PosActual.Z -= VelocidadSubida * DeltaTime;

			if (PosActual.Z <= 0.f)
			{
				PosActual.Z = 0.f;
				bSubiendo = true; // vuelve a subir
			}
		}

		LaberintoRoot->SetRelativeLocation(PosActual);
	}

	// Rotación (solo si está activado)
	if (bRotando)
	{
		FRotator RotacionActual = LaberintoRoot->GetComponentRotation();
		RotacionActual.Yaw += 45.0f * DeltaTime;
		LaberintoRoot->SetWorldRotation(RotacionActual);
	}

}

void ALaberintoUno::LaberintoMaguico()
{
	bRotando = true;
	bVolando = false;

	for (int32 fila = 0; fila < MapaLab.Num(); ++fila)
	{
		for (int32 columna = 0; columna < MapaLab[fila].Num(); ++columna)
		{
			int32 valor = MapaLab[fila][columna];
			if (valor != 0)
			{
				FVector posicionBloque = FVector(
					XInicial + columna * AnchoBloque,
					YInicial + fila * LargoBloque,
					125.0f);

				ABloque* Bloque = nullptr;

				switch (valor)
				{
				case 1:
					Bloque = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionBloque, FRotator::ZeroRotator);
					break;
				case 2:
					Bloque = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), posicionBloque, FRotator::ZeroRotator);
					break;
				case 3:
					Bloque = GetWorld()->SpawnActor<ABloqueVidrio>(ABloqueVidrio::StaticClass(), posicionBloque, FRotator::ZeroRotator);
					break;
				case 4:
					Bloque = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionBloque, FRotator::ZeroRotator);
					break;
				}

				if (Bloque)
				{
					// Adjuntar al componente raíz del actor del laberinto
					Bloque->AttachToComponent(LaberintoRoot, FAttachmentTransformRules::KeepWorldTransform);
				}
			}
		}
	}

}

void ALaberintoUno::LaberintoVolador()
{
	bRotando = false;
	bVolando = true;
	bSubiendo = true;
	ABloque* Bloques = nullptr;

	for (int32 fila = 0; fila < MapaLab.Num(); ++fila)
	{
		for (int32 columna = 0; columna < MapaLab[fila].Num(); ++columna)
		{
			int32 valor = MapaLab[fila][columna];
			if (valor != 0) // Si no es espacio vacío
			{
				// Calculamos la posición del bloque
				FVector posicionBloque = FVector(
					XInicial + columna * AnchoBloque,
					YInicial + fila * LargoBloque,
					125.0f); // Z queda en 0 (altura del bloque)
				switch (valor)
				{
				case 1:
					Bloques = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionBloque, FRotator::ZeroRotator);
					break;
				case 2:
					Bloques = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), posicionBloque, FRotator::ZeroRotator);
					break;
				case 3:
					Bloques = GetWorld()->SpawnActor<ABloqueVidrio>(ABloqueVidrio::StaticClass(), posicionBloque, FRotator::ZeroRotator);
					break;
				case 4:
					Bloques = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionBloque, FRotator::ZeroRotator);
					break;
				}

				if (Bloques)
				{
					// Cambiamos el padre del bloque al LaberintoRoot para que se mueva junto
					Bloques->AttachToComponent(LaberintoRoot, FAttachmentTransformRules::KeepWorldTransform);
				}
			}
		}
	}
}