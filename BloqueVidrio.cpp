// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueVidrio.h"

ABloqueVidrio::ABloqueVidrio() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Glass.M_Glass'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}

void ABloqueVidrio::ComportamientoIndividual(float DeltaTime)
{
    FVector EscalaActual = GetActorScale3D();

    if (bEscalandoAumentando)
    {
        // Escalar hacia la escala máxima
        EscalaActual = FMath::VInterpTo(EscalaActual, EscalaMaxima, DeltaTime, VelocidadEscalado);

        SetActorScale3D(EscalaActual);

        if (EscalaActual.Equals(EscalaMaxima, 0.01f))
        {
            bEscalandoAumentando = false;
        }
    }
    else
    {
        // Escalar de regreso a la escala original
        EscalaActual = FMath::VInterpTo(EscalaActual, EscalaInicial, DeltaTime, VelocidadEscalado);

        SetActorScale3D(EscalaActual);

        if (EscalaActual.Equals(EscalaInicial, 0.01f))
        {
            bEscalandoAumentando = true;
        }
    }
}
// Called when the game starts or when spawned
void ABloqueVidrio::BeginPlay()
{
    Super::BeginPlay();
    EscalaInicial = GetActorScale3D();
    EscalaMaxima = EscalaInicial * 2.3f; // Aumenta un 30% el tamaño original
}

// Called every frame
void ABloqueVidrio::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ComportamientoIndividual(DeltaTime);
}

