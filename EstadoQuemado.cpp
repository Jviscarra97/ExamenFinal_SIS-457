// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoQuemado.h"
#include "BloquePasto.h"

// Sets default values
AEstadoQuemado::AEstadoQuemado()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoQuemado::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoQuemado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoQuemado::EjecutarEstado_Implementation(ABloquePasto* BloquePasto)
{
	// Lógica cuando está quemado, por ejemplo desaparecer
	UE_LOG(LogTemp, Warning, TEXT("Bloque quemado"));

	BloquePasto->Destroy(); // Se destruye completamente
}

