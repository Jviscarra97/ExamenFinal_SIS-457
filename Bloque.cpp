// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque.h"

// Sets default values
ABloque::ABloque()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object); // asignamos la malla al componente Mesh
		
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f)); // Establecemos el tamaño del bloque
	}

	FloatSpeed = 5.0f;
	RotationSpeed = 3.0f;

	bPuedeMoverse = FMath::RandBool();
	TipoMovimiento = -1;
	FloatSpeed = 100.0f;
	bPuedeMoverse = false;
	DireccionMovimientoX = 1; // Direccion de movimiento en X
	DireccionMovimientoY = 1; // Direccion de movimiento en Y
	DireccionMovimientoZ = 1; // Direccion de movimiento en Z
}


 //Clona el bloque actual y devuelve un nuevo actor del mismo tipo

//AActor* ABloque::clon() const 
//{
//	if (!GetWorld()) // Verifica si el mundo es válido
//	{
//		UE_LOG(LogTemp, Error, TEXT("GetWorld() es NULL en clon()")); // Esto puede ocurrir si el actor no está en un mundo válido
//		return nullptr; // No se puede clonar si no hay un mundo válido
//	}
//	// Crea un nuevo actor del mismo tipo en la misma ubicación y rotación que el actual
//	ABloque* nueva = GetWorld()->SpawnActor<ABloque>(GetClass(), GetActorLocation(), GetActorRotation()); 
//	
//	if (!nueva) // Verifica si la creación del actor fue exitosa
//	{
//		// Si no se pudo crear el clon, registra un error
//		UE_LOG(LogTemp, Error, TEXT("Error al crear el clon de la Bloque"));
//		return nullptr; // No se pudo crear el clon
//	}
//
//	return Cast<AActor>(nueva); // Devuelve el nuevo actor clonado
//}


// Metodo para el patron factory, crea un bloque de un tipo especifico
// Comportamiento individual del bloque, se puede sobreescribir en las clases hijas
void ABloque::ComportamientoIndividual(float DeltaTime)
{
	// Comportamiento individual por defecto, puede ser sobreescrito en clases hijas
	UE_LOG(LogTemp, Warning, TEXT("bloque"));
}
///comportaminento grupal, en este caso mueve el bloque hacia arriba para todos los tipos de bloques
void ABloque::ComportamientoGrupal()
{
	// Comportamiento grupal por defecto, puede ser sobreescrito en clases hijas
	FVector PosicionActual = GetActorLocation(); // Obtiene la posición actual del bloque
	FVector NuevaPosicion = PosicionActual + FVector(0.f, 0.f, 200.f); // 100 unidades arriba

	SetActorLocation(NuevaPosicion); // Actualiza la posición del bloque
}

// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();
	// Inicializa la posición inicial del bloque
	PosicionInicial = GetActorLocation(); // Guardamos la posición inicial del bloque
	
}

// Called every frame
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Para el patron factory
	// tambien para el patron facade  
	/*MoverBloque(DeltaTime);*/

	if (bPuedeMoverse)
	{
		FVector Pos = GetActorLocation();
		float Movimiento = FloatSpeed * DeltaTime;
		float RangoMax = 300.0f;
		bool AjustarDireccion = false;

		// Verificar si alcanz? el rango m?ximo en cualquier eje
		if (FMath::Abs(Pos.X - PosicionInicial.X) >= RangoMax && DireccionMovimientoX != 0)
		{
			DireccionMovimientoX *= -1;
			AjustarDireccion = true;
		}
		if (FMath::Abs(Pos.Y - PosicionInicial.Y) >= RangoMax && DireccionMovimientoY != 0)
		{
			DireccionMovimientoY *= -1;
			AjustarDireccion = true;
		}
		if (FMath::Abs(Pos.Z - PosicionInicial.Z) >= RangoMax && DireccionMovimientoZ != 0)
		{
			DireccionMovimientoZ *= -1;
			AjustarDireccion = true;
		}

		// Aplicar movimiento en cada eje seg?n corresponda
		if (DireccionMovimientoX != 0)
			Pos.X += DireccionMovimientoX * Movimiento;
		if (DireccionMovimientoY != 0)
			Pos.Y += DireccionMovimientoY * Movimiento;
		if (DireccionMovimientoZ != 0)
			Pos.Z += DireccionMovimientoZ * Movimiento;

		SetActorLocation(Pos);
	}
}

//// Para el patron factory
//void ABloque::IniciarMovimiento(FVector NuevaPosObjetivo, float Tiempo)
//{
//	PosInicial = GetActorLocation(); // Guardamos la posición inicial
//	PosFinal = NuevaPosObjetivo; // Establecemos la nueva posición objetivo
//	TiempoDeMovimiento = Tiempo; // Establecemos el tiempo de movimiento
//	TiempoTranscurrido = 0.0f; // Reiniciamos el tiempo transcurrido
//}
//void ABloque::MoverBloque(float DeltaTime)
//{
//	if (TiempoTranscurrido < TiempoDeMovimiento)
//	{
//		// Calculamos el porcentaje de tiempo transcurrido
//		TiempoTranscurrido += DeltaTime;
//		float progreso = FMath::Clamp(TiempoTranscurrido / TiempoDeMovimiento, 0.0f, 1.0f);
//		
//		// Interpolamos la posición usando Lerp
//		FVector NuevaPos = FMath::Lerp(PosInicial, PosFinal, progreso);
//		SetActorLocation(NuevaPos); // Actualizamos la posición del bloque
//		
//	}
//}

