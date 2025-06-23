// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoVerde.h"
#include "BloquePasto.h"
#include "IBloquePastoState.h"

ABloquePasto::ABloquePasto() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);
		}
		
		static ConstructorHelpers::FObjectFinder<UMaterialInterface> MatVerde(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'"));
		if (MatVerde.Succeeded())
		{
			MaterialVerde = MatVerde.Object;
		}

		static ConstructorHelpers::FObjectFinder<UMaterialInterface> MatQuemado(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
		if (MatQuemado.Succeeded())
		{
			MaterialQuemado = MatQuemado.Object;
		}
	}
	
	


}

void ABloquePasto::BeginPlay()
{
	// Estado inicial
	if (UWorld* World = GetWorld())
	{
		AEstadoVerde* EstadoInicial = World->SpawnActor<AEstadoVerde>();
		CambiarEstado(EstadoInicial);
	}
}

void ABloquePasto::Tick(float DeltaTime)
{
	EjecutarEstado();
}


void ABloquePasto::CambiarEstado(AActor* NuevoEstado)
{
	if (EstadoActual)
	{
		EstadoActual->Destroy();
	}
	EstadoActual = NuevoEstado;
}

void ABloquePasto::EjecutarEstado()
{
	if (EstadoActual && EstadoActual->GetClass()->ImplementsInterface(UIBloquePastoState::StaticClass()))
	{
		IIBloquePastoState::Execute_EjecutarEstado(EstadoActual, this);
	}
}
AActor* ABloquePasto::ObtenerEstadoActual() const
{
	return EstadoActual;
}

void ABloquePasto::AplicarMaterialEstado(FString NombreEstado)
{
	if (!Mesh) return;

	if (NombreEstado.Equals(TEXT("Verde")))
	{
		Mesh->SetMaterial(0, MaterialVerde);
	}
	else if (NombreEstado.Equals(TEXT("Quemado")))
	{
		Mesh->SetMaterial(0, MaterialQuemado);
	}
}
