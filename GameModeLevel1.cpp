// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel1.h"
#include "Enemigo.h"
#include "Enemigo_Aereo.h"
#include "Enemigo_Subterraneo.h"
#include "Enemigo_Terrestre.h"
#include "Enemigo_Acuatico.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueLadrillo.h"
#include "BloqueConcreto.h"
#include "BloqueMadera.h"
#include "BloqueCuarzo.h"
#include "BloqueBurbuja.h"
#include "BloqueVidrio.h"
#include "BloqueHielo.h"
#include "BloqueOro.h"
#include "BloquePasto.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
AGameModeLevel1::AGameModeLevel1() {
	
    PrimaryActorTick.bCanEverTick = true;
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}
void AGameModeLevel1::BeginPlay()
{
    Super::BeginPlay();
    
}

