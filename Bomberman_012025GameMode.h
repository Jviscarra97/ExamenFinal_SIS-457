// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "GameFramework/GameModeBase.h"
#include "Bomberman_012025GameMode.generated.h"

class AMoneda;
class AFactoryBloque;

UCLASS(minimalapi)
class ABomberman_012025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABomberman_012025GameMode();

	virtual void BeginPlay() override;
	// Mapa del juego que esta siendo utilizado en el patron factory
    TArray<TArray<int32>> aMapaBloques = {
       {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
       {1,3,1,0,4,0,1,3,2,0,4,0,0,0,0,0,1,0,0,1},
       {1,0,1,0,2,0,1,0,1,1,5,0,1,2,1,0,1,0,0,1},
       {1,0,0,0,2,0,0,4,0,0,1,0,0,0,1,0,4,0,0,1},
       {1,2,2,0,1,1,1,1,2,0,2,1,1,0,1,1,2,1,0,1},
       {1,0,0,0,0,4,0,0,2,0,0,0,1,0,0,0,4,0,0,1},
       {1,0,2,2,1,1,1,0,1,1,1,0,2,1,1,1,1,2,0,1},
       {1,4,1,4,0,0,1,0,0,0,1,0,0,0,1,3,0,1,0,1},
       {1,1,2,0,2,1,1,1,2,0,1,1,1,0,1,1,0,1,4,1},
       {1,1,3,0,2,0,0,0,4,0,0,0,1,0,0,0,0,0,0,1},
       {1,2,1,4,1,1,1,4,1,1,1,0,2,1,1,0,1,1,2,1},
       {1,1,0,0,0,0,1,5,5,5,1,0,0,0,2,4,0,0,0,1},
       {1,3,1,2,1,0,2,1,1,0,1,1,1,0,1,1,1,1,0,1},
       {1,0,1,0,0,4,0,0,1,4,0,0,1,0,0,4,0,0,0,1},
       {1,0,1,0,2,1,1,0,2,1,1,0,2,2,1,1,1,1,0,1},
       {1,0,0,0,1,0,0,4,0,0,1,0,4,0,0,0,0,1,0,1},
       {1,1,1,0,1,0,2,1,1,0,1,2,2,1,1,1,0,1,0,1},
       {1,0,4,0,0,0,1,3,0,0,0,0,0,4,0,0,0,0,0,1},
       {1,0,1,1,1,1,1,0,2,1,2,1,2,1,4,2,1,2,4,1},
       {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5}
    };
    //Parametros para el spawn del mapa
    float XInicial = 100.0f;
    float YInicial = 100.0f;
    float AnchoBloque = 100.0f;
    float LargoBloque = 100.0f;

	//para el spawn de los bloques
    ABloque* BloqueActual = nullptr;
    TArray<ABloque*> aBloques;

    //para el patron factory//
    AFactoryBloque* FabricadeBloques;


    ///para almacenar los bloques generados en el laberinto con un id unico////
    TArray<ABloque*> ArregloBloques;
    int32 ContadorID = 0;
    void ActivarComportamientoGrupal();//para activar comportamineto grupal
	// hasta aqui es el patron factory //

    /////// /// para el  patron builder solo es esto ///////// 
    class ADirector* Director;
    class ABuilderConcreto* Builder;
    /// //////////////////////////


    void SpawnBloque(FVector posicionBloque, int32 tipoBloque);
    // Add the declaration of PuntoVacio as a TArray to store FVector values  
    TArray<FVector> PuntoVacio;
    void OtraMitadLaberinto(FVector posicionInicial,
        FVector desplazamientoFila,
        FVector desplazamientoColumna);
    void clonarbloques(FVector posicionBloque, int32 tipoBloque);
   
    
    UPROPERTY()
    ABloque* ProtoMadera;
    UPROPERTY()
    ABloque* ProtoLadrillo;

    UPROPERTY()
    ABloque* ProtoAcero;

    UPROPERTY()
    ABloque* ProtoVidrio;
    
    //patron memento
protected:
    UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class AOriginadorConcreto* Jugador;

	UPROPERTY(VisibleAnywhere, Category = "Game mode")
	class ACuidador* Cuidador;

public: 
	void GuardarJuego();
	void CargarJuego();

   

    //patron state
    UPROPERTY()
    class ABloquePasto* BloquePrueba;
    void CambiarEstadoABloqueQuemado();

    //tiempo para cambiar estado del bloque quemado 
    FTimerHandle TimerCambioEstado;

	//funcion que alterna el estado del bloque quemado
	void alternarEstadoBloqueQuemado();
};



