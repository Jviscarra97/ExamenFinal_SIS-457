// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Prototype.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moneda.generated.h"


UCLASS()
class BOMBERMAN_012025_API AMoneda : public AActor, public IPrototype
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoneda();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes") // Malla del objeto
	UStaticMeshComponent* Meash;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes") // Colision
	class UBoxComponent* Trigger;
	
	///////////////patron prototype////////////////////
	// Declaración de un método virtual sobrescrito que implementa el patrón Prototype.
// 'virtual' permite que las clases derivadas sobrescriban este método.
// 'AActor*' indica que el método devuelve un puntero a un objeto de tipo AActor (o derivado).
// 'clon()' es el nombre del método que se encargará de crear una copia del objeto actual.
// 'const' indica que este método no modificará el estado del objeto.
// 'override' indica que este método está sobrescribiendo una versión virtual del mismo método en la clase base.//
	virtual  AActor* clon()  const override;

	

	// Ventanas conectadas para teletransportaci?n
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleport")
	TArray<AMoneda*> Moneda;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotacion")
	float velocidadRotacional;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotacion")
	float anguloMaximoRotacion;

	int ValorMoneda;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float anguloActual;
	bool rotandoHaciaDerecha;
	///para que no se repita la colision//para desacer monedas//
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//
};
