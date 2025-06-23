// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "LaberintosFacade.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaberintoUno.generated.h"

UCLASS()
class BOMBERMAN_012025_API ALaberintoUno : public ALaberintosFacade 
    // cambiar ALaberintosFacade por la clase base que 
    //estés utilizando para los laberintos o cambiar AActor para los otros patrones
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaberintoUno();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    //Matriz del ecenario donde se guardan los valores de cada bloque,moneda,puerta y enemigo
    TArray<TArray<int32>> MapaLaberinto =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,6,1,0,5,0,1,5,2,0,5,0,0,0,0,0,1,0,6,1},
        {1,0,1,0,2,0,1,0,1,1,5,0,1,2,1,0,1,0,0,1},
        {1,0,7,0,4,0,0,4,0,0,4,0,7,7,4,0,5,0,0,1},
        {1,2,2,0,4,4,4,4,4,0,4,4,4,0,4,4,4,1,0,1},
        {1,0,0,0,0,5,7,0,3,0,0,0,3,0,0,0,5,0,0,1},
        {1,0,2,4,4,3,3,0,3,3,3,0,3,3,3,4,4,2,0,1},
        {1,5,1,5,0,0,3,0,0,0,3,0,0,0,3,5,0,1,0,1},
        {1,1,2,7,4,3,3,3,3,0,3,3,3,0,3,4,0,1,5,1},
        {1,1,5,0,4,0,0,0,5,7,0,0,3,0,0,7,0,0,0,1},
        {1,2,1,5,4,3,3,5,3,3,3,0,3,3,3,0,4,1,2,1},
        {1,1,0,0,0,0,3,0,0,0,3,0,0,0,3,5,0,0,0,1},
        {1,5,1,4,4,0,3,3,3,0,3,3,3,0,3,4,4,1,0,1},
        {1,0,1,0,0,5,7,0,3,5,0,0,3,0,0,5,0,0,0,1},
        {1,0,1,0,4,3,3,0,3,3,3,0,3,3,3,4,4,1,0,1},
        {1,0,0,0,4,0,0,5,0,0,4,7,5,0,0,0,0,1,0,1},
        {1,1,1,0,4,0,4,4,4,0,4,4,4,4,4,4,0,1,0,1},
        {1,7,5,0,0,0,1,5,0,0,0,0,0,5,0,0,7,0,0,1},
        {1,6,1,1,1,1,1,7,2,1,2,1,2,1,5,2,1,2,6,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

	// Variables para controlar el movimiento del laberinto entra en el patron facade

    UPROPERTY(EditAnywhere, Category = "Movimiento")
    bool bVolando = false;

    UPROPERTY(EditAnywhere, Category = "Movimiento")
    bool bSubiendo = false;

    UPROPERTY(EditAnywhere, Category = "Movimiento")
    bool bRotando = false; // ? para controlar si gira o no
    UPROPERTY()
    USceneComponent* LaberintoRoot;
    virtual void LaberintoMaguico() override;

    virtual void LaberintoVolador() override;
    // Para animar la elevación
    float AlturaObjetivo = 800.f;  // Cuánto subir (en unidades Unreal)
    float VelocidadSubida = 100.f; // Velocidad de subida/bajada

    TArray<TArray<int32>> MapaLab =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,6,1,0,5,0,1,5,2,0,5,0,0,0,0,0,1,0,6,1},
        {1,0,1,0,2,0,1,0,1,1,5,0,1,2,1,0,1,0,0,1},
        {1,0,7,0,4,0,0,4,0,0,4,0,7,7,4,0,5,0,0,1},
        {1,2,2,0,4,4,4,4,4,0,4,4,4,0,4,4,4,1,0,1},
        {1,0,0,0,0,5,7,0,3,0,0,0,3,0,0,0,5,0,0,1},
        {1,0,2,4,4,3,3,0,3,3,3,0,3,3,3,4,4,2,0,1},
        {1,5,1,5,0,0,3,0,0,0,3,0,0,0,3,5,0,1,0,1},
        {1,1,2,7,4,3,3,3,3,0,3,3,3,0,3,4,0,1,5,1},
        {1,1,5,0,4,0,0,0,5,7,0,0,3,0,0,7,0,0,0,1},
        {1,2,1,5,4,3,3,5,3,3,3,0,3,3,3,0,4,1,2,1},
        {1,1,0,0,0,0,3,0,0,0,3,0,0,0,3,5,0,0,0,1},
        {1,5,1,4,4,0,3,3,3,0,3,3,3,0,3,4,4,1,0,1},
        {1,0,1,0,0,5,7,0,3,5,0,0,3,0,0,5,0,0,0,1},
        {1,0,1,0,4,3,3,0,3,3,3,0,3,3,3,4,4,1,0,1},
        {1,0,0,0,4,0,0,5,0,0,4,7,5,0,0,0,0,1,0,1},
        {1,1,1,0,4,0,4,4,4,0,4,4,4,4,4,4,0,1,0,1},
        {1,7,5,0,0,0,1,5,0,0,0,0,0,5,0,0,7,0,0,1},
        {1,6,1,1,1,1,1,7,2,1,2,1,2,1,5,2,1,2,6,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    //Parametros para el spawn del mapa
    float XInicial = -1830.0f;
    float YInicial = -1200.0f;
    float AnchoBloque = 100.0f;
    float LargoBloque = 100.0f;
    class ABloque* BloqueActual = nullptr;
};
