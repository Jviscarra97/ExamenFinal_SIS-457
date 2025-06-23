// Fill out your copyright notice in the Description page of Project Settings.


#include "LaberintosFacade.h"
#include "Director.h"
#include "BuilderConcreto.h"
#include "LaberintoUno.h"

// Sets default values
ALaberintosFacade::ALaberintosFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALaberintosFacade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaberintosFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaberintosFacade::LaberintoBuilder()
{
	Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());
	Builder = GetWorld()->SpawnActor<ABuilderConcreto>(ABuilderConcreto::StaticClass());
	Director->LlamarConstructor(Builder);
	Director->ConstruirLaberinto();
	ALaberintoUno* Laberinto = Director->GetLaberinto();
}