// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bomberman_012025GameMode.h"
#include "Facade.h"
#include "Moneda.h"
#include "Bloque.h"
#include "FactoryBloque.h"
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
#include "Bomberman_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "LaberintoUno.h"
#include "Director.h"
#include "BuilderConcreto.h"
#include "Prototype.h"
#include "GrupoEnemigo.h"
#include "Enemigo.h"
#include "Enemigo_Terrestre.h"
#include "Enemigo_Aereo.h"
#include "Kismet/GameplayStatics.h"
#include "Cuidador.h"
#include "OriginadorConcreto.h"
#include "EstadoQuemado.h"
#include "EstadoVerde.h"


ABomberman_012025GameMode::ABomberman_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABomberman_012025GameMode::BeginPlay()
{
	Super::BeginPlay();

    ////////solo esto tiene que ver con el patron  builder /////////
    ////////// el gamemode es el cliente y es el que llama al director y al builder  para la entrega final//////
    //Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());
    //Builder = GetWorld()->SpawnActor<ABuilderConcreto>(ABuilderConcreto::StaticClass());
    //Director->LlamarConstructor(Builder);
    //Director->ConstruirLaberinto();
    //ALaberintoUno* Laberinto = Director->GetLaberinto();
    ////////////////////////////////////////////////////////


//    // solo es este el patron factory para generar los bloques//
//    FabricadeBloques = GetWorld()->SpawnActor<AFactoryBloque>(AFactoryBloque::StaticClass());
//    // Recorremos la matriz para generar los bloques
//    ABloque* NuevoBloque = nullptr;
//
//    for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
//    {
//        for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
//        {
//            int32 valor = aMapaBloques[fila][columna];
//            if (valor != 0) // Si no es espacio vacío
//            {
//                // Calculamos la posición del bloque
//                FVector posicionBloque = FVector(
//                    XInicial + columna * AnchoBloque,
//                    YInicial + fila * LargoBloque,
//                    125.0f); // Z queda en 0 (altura del bloque)
//
//                // Llamamos a la función para generar un bloque
//                //SpawnBloque(posicionBloque, valor);
//                switch (valor)
//                {
//                case 1: // Madera
//                    NuevoBloque = FabricadeBloques->CrearBloque("Madera", posicionBloque);
//                    //SpawnBloque(posicionBloque, 1);
//                    break;
//                case 2: // Ladrillo
//                    NuevoBloque = FabricadeBloques->CrearBloque("Ladrillo", posicionBloque);
//                    break;
//                case 3: // Magico
//                    NuevoBloque = FabricadeBloques->CrearBloque("Vidrio", posicionBloque);
//                    break;
//                case 4: // Acero
//                    NuevoBloque = FabricadeBloques->CrearBloque("Acero", posicionBloque);
//                    break;
//                case 5: // Oro
//                    NuevoBloque = FabricadeBloques->CrearBloque("Oro", posicionBloque);
//                    break;
//                default:
//                    break;
//                }
//
//                if (NuevoBloque)
//                {
//                    NuevoBloque->IDBloque = ContadorID;
//                    ArregloBloques.Add(NuevoBloque);
//                    ContadorID++;
//                }
//            }
//        }
//    }
//    ActivarComportamientoGrupal();  //llama para una funcion grupal
//}

//void ABomberman_012025GameMode::ActivarComportamientoGrupal()
//{
//	for (ABloque* Bloque : ArregloBloques) // recorre el arreglo de bloques
//    {
//		if (Bloque) // Verifica que el bloque no sea nulo
//        {
//			Bloque->ComportamientoGrupal(); // Llama al comportamiento grupal de cada bloque
//        }
//    }
//}

	//Hasta aqui el patron factory para generar los bloques//

	//para el patron prototype, clon que devuelve un puntero a un objeto de tipo AActor (o derivado)///
	
	//AMoneda* Monedita = GetWorld()->SpawnActor<AMoneda>(AMoneda::StaticClass(), FVector(-740.f, -100.f, 180.f), FRotator(0, 0, 0));
	//if (Monedita)
	//{
	//	//Monedita->SetActorScale3D(FVector(1.5f, 1.5f, 1.5f)); // Cambiar tamaño
	//	UE_LOG(LogTemp, Warning, TEXT("Moneda original spawneada correctamente."));
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Error, TEXT("Error: No se pudo spawnear la moneda original."));
	//	return; // Salir de la función si Monedita es NULL  
	//}
   
    //for (int32 fila = 0; fila < aMapaBloques.Num(); fila++)
    //{
    //    for (int32 col = 0; col < aMapaBloques[fila].Num(); col++)
    //    {
    //        if (aMapaBloques[fila][col] == 1)
    //        {
    //            // Clonar desde el prototipo
    //            IPrototype* clon = Cast<IPrototype>(Monedita->clon());
    //            if (clon)
    //            {
    //                AMoneda* clonedMoneda = Cast<AMoneda>(clon);
    //                if (clonedMoneda)
    //                {
    //                    // La posición se define directamente por fila y columna * escala deseada
    //                    FVector posicionEnMapa = FVector(
    //                        -740.f + col * 100.f,   // X (columna)
    //                        -100.f + fila * 100.f,  // Y (fila)
    //                        180.f                   // Z constante
    //                    );

    //                    clonedMoneda->SetActorLocation(posicionEnMapa);
    //                    clonedMoneda->ValorMoneda = ((fila + col) % 2 == 0) ? 50 : 100;

    //                    UE_LOG(LogTemp, Warning, TEXT("Moneda clonada en fila %d, col %d con valor: %d"), fila, col, clonedMoneda->ValorMoneda);
    //                }
    //            }
    //        }
    //    }
    //}

    ////////////////////////////////////////////////////////////////////
   //el patron facade /////////////////////////
    AFacade* MiFacade = GetWorld()->SpawnActor<AFacade>(AFacade::StaticClass());
    if (MiFacade)
    {
        // Llamar al nivel que quieras
        //MiFacade->nivel1();//construir el laberinto magico
        //MiFacade->nivel2();//contulle el laberinto volador
        //MiFacade->nivel3(); //construir el laberinto con el builder
    }


//////Patron Composite donde manda las oredes a los enemigos y tambien para que se  comporten como un grupo//////
    ///////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////
AGrupoEnemigo* GrupoPrincipal = GetWorld()->SpawnActor<AGrupoEnemigo>();
if (!GrupoPrincipal)
{
    UE_LOG(LogTemp, Error, TEXT("No se pudo crear el GrupoEnemigo"));
    return;
}

// Crear enemigos en tiempo de ejecución (ejemplo 5 enemigos)
for (int i = 0; i < 15; ++i)
{
    FVector SpawnLocation = FVector(i * -340.f, -100.f, 180.f); // Distribuye en X
    FRotator SpawnRotation = FRotator::ZeroRotator;

    AActor* NuevoEnemigo = nullptr;

    int TipoEnemigo = i % 3; // 0: normal, 1: volador, 2: explosivo
    switch (TipoEnemigo)
    {
    case 0: // Enemigo normal
        NuevoEnemigo = GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), SpawnLocation, SpawnRotation);
        break;

    case 1: // Enemigo volador
        NuevoEnemigo = GetWorld()->SpawnActor<AEnemigo_Aereo>(AEnemigo_Aereo::StaticClass(), SpawnLocation, SpawnRotation);
        break;

    case 2: // Enemigo explosivo
        NuevoEnemigo = GetWorld()->SpawnActor<AEnemigo_Terrestre>(AEnemigo_Terrestre::StaticClass(), SpawnLocation, SpawnRotation);
        break;
    }
    if (NuevoEnemigo)
    {
        // Agregar al grupo usando la interfaz
        if (NuevoEnemigo && NuevoEnemigo->GetClass()->ImplementsInterface(UIEnemigoComposite::StaticClass()))
        {
            TScriptInterface<IIEnemigoComposite> EnemigoComoInterfaz;
            EnemigoComoInterfaz.SetObject(NuevoEnemigo);
            EnemigoComoInterfaz.SetInterface(Cast<IIEnemigoComposite>(NuevoEnemigo));

            GrupoPrincipal->AgregarEnemigo(EnemigoComoInterfaz);
        }
    }
}
// Ahora que tienes el grupo con enemigos, usa sus métodos
   //GrupoPrincipal->Mover(FVector(100, 0, 0));  // Mueve todos
GrupoPrincipal->Atacar();                    // Todos atacan
GrupoPrincipal->Protegerse();        // se protegen todos

//patron memento 
Jugador = GetWorld()->SpawnActor<AOriginadorConcreto>(AOriginadorConcreto::StaticClass());
Cuidador = GetWorld()->SpawnActor<ACuidador>(ACuidador::StaticClass());

int32 Vidas = Jugador->ObtenerVidas();
GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("Vidas: %d"), Vidas));

GuardarJuego();
CargarJuego();

//patron state

// Iniciar timer para cambiar de estado cada 3 segundos
GetWorld()->GetTimerManager().SetTimer(TimerCambioEstado, this, &ABomberman_012025GameMode::alternarEstadoBloqueQuemado, 3.0f, true);

UWorld* World = GetWorld();
if (World)
{
    // Spawnear bloque pasto
    FVector Posicion(0.f, 0.f, 200.f); // posición en el mapa
    FActorSpawnParameters Params;

    BloquePrueba = World->SpawnActor<ABloquePasto>(ABloquePasto::StaticClass(), Posicion, FRotator::ZeroRotator, Params);

    if (BloquePrueba)
    {
        // Obtener el estado actual y mostrar su nombre
        AActor* Estado = BloquePrueba->ObtenerEstadoActual();
        if (Estado && Estado->GetClass()->ImplementsInterface(UIBloquePastoState::StaticClass()))
        {
            FString NombreEstado = IIBloquePastoState::Execute_ObtenerNombreEstado(Estado);
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Estado actual: %s"), *NombreEstado));
        }
    }
}
CambiarEstadoABloqueQuemado();
alternarEstadoBloqueQuemado();
}


// patron Memento para guardar y cargar el estado del juego
void ABomberman_012025GameMode::GuardarJuego()
{
    if(Jugador && Cuidador) {
        Jugador->EstablecerVidas(5);
        Cuidador->Guardar(Jugador);
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Juego Guardado")));

        int32 Vidas = Jugador->ObtenerVidas();
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("Vidas: %d"), Vidas));
    }
}

void ABomberman_012025GameMode::CargarJuego()
{
    if (Jugador && Cuidador) {
        Cuidador->Cargar(Jugador);
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Juego Cargado")));

        int32 Vidas = Jugador->ObtenerVidas();
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("Vidas: %d"), Vidas));
    }
}


void ABomberman_012025GameMode::CambiarEstadoABloqueQuemado()
{
    if (BloquePrueba && GetWorld())
    {
        AEstadoQuemado* NuevoEstado = GetWorld()->SpawnActor<AEstadoQuemado>();
        BloquePrueba->CambiarEstado(NuevoEstado);

        FString NombreEstado = IIBloquePastoState::Execute_ObtenerNombreEstado(NuevoEstado);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Nuevo estado: %s"), *NombreEstado));
    }
}

void ABomberman_012025GameMode::alternarEstadoBloqueQuemado()
{
   if (!BloquePrueba || !GetWorld()) return;

        AActor* EstadoActual = BloquePrueba->ObtenerEstadoActual();
       
        // Verificamos qué estado tiene y alternamos
        if (EstadoActual->GetClass()->IsChildOf(AEstadoVerde::StaticClass()))
        {
            AEstadoQuemado* NuevoEstado = GetWorld()->SpawnActor<AEstadoQuemado>();
            BloquePrueba->CambiarEstado(NuevoEstado);

            FString Nombre = IIBloquePastoState::Execute_ObtenerNombreEstado(NuevoEstado);
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Estado cambiado a: %s"), *Nombre));
        }
        else
        {
            AEstadoVerde* NuevoEstado = GetWorld()->SpawnActor<AEstadoVerde>();
            BloquePrueba->CambiarEstado(NuevoEstado);

            FString Nombre = IIBloquePastoState::Execute_ObtenerNombreEstado(NuevoEstado);
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Estado cambiado a: %s"), *Nombre));
            BloquePrueba->AplicarMaterialEstado(Nombre);
        }
        
}
