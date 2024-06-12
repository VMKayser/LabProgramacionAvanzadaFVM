// Fill out your copyright notice in the Description page of Project Settings.


#include "Figura.h"

// Sets default values
AFigura::AFigura()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//creamos malla para la figura
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT(" StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	// Crea la malla de nave enemiga
	mallaFigura = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaFigura->SetStaticMesh(ShipMesh.Object);
	mallaFigura->SetupAttachment(RootComponent);
	RootComponent = mallaFigura;

	velocidad = 300.0f;
	MovimientoDerecha = true;
	MovimientoArriba = true;
	numerociclos = 0;
	band = true;
	
}

// Called when the game starts or when spawned
void AFigura::BeginPlay()
{
	Super::BeginPlay();
	UbicacionInicial = GetActorLocation();
	UbicacionFinal = UbicacionInicial;

	
}

// Called every frame
void AFigura::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverDiagonal(DeltaTime);
	

}

void AFigura::crearobjetos(int numobj)
{
	const FRotator SpawnRotation = FRotator::ZeroRotator;
	UWorld* const World = GetWorld();
	UbicacionFinal = GetActorLocation();
	if (World)
	{
		for (int i = 0; i < numobj; ++i)
		{
			
			 UbicacionFinal += FVector(0.0f, 0.0f, 200.0f);
			AShape* NuevoObjeto= World->SpawnActor<AShape>( UbicacionFinal, SpawnRotation);
			if (NuevoObjeto)
			{
				Objetos.Add(NuevoObjeto);
			}
		}
	}
}


void AFigura::caerobjetos(int numobj)
{
	for (int32 i = 0; i < 2; i++)
	{
		AShape* NuevoObjeto = Objetos[0];
		if (NuevoObjeto)
		{
			NuevoObjeto->fisicas();
			Objetos.Remove(NuevoObjeto);
			
		}
	}
	
	
	
}

void AFigura::MoverDiagonal(float DeltaTime)
{
	// Nueva posición considerando movimiento diagonal
	FVector NENuevaPosicion = GetActorLocation() +
		FVector(MovimientoArriba ? velocidad : -velocidad, MovimientoDerecha ? velocidad : -velocidad,0.0f ) * DeltaTime;

	// Actualiza la posición del objeto
	SetActorLocation(NENuevaPosicion);
	if (band) {
		// Condiciones para cambiar de dirección horizontalmente
		if (MovimientoDerecha && GetActorLocation().Y >= 250.0f)
		{
			MovimientoDerecha = false;

		}
		else if (!MovimientoDerecha && GetActorLocation().Y <= -250.0f)
		{
			MovimientoDerecha = true;
		}
	}
	else
	{
		if (MovimientoDerecha && GetActorLocation().Y >= -250.0f)
		{
			MovimientoDerecha = false;

		}
		else if (!MovimientoDerecha && GetActorLocation().Y <= 250.0f)
		{
			MovimientoDerecha = true;
		}
	}
	// Condiciones para cambiar de dirección verticalmente
	if (MovimientoArriba && GetActorLocation().X >= 250.0f)
	{
		MovimientoArriba = false;


	}
	else if (!MovimientoArriba && GetActorLocation().X <= -250.0f)
	{
		MovimientoArriba = true;
		numerociclos++;
		if (numerociclos == 4)
		{
			crearobjetos(10);
		}
		if (numerociclos >= 5)
		{
			caerobjetos(2);
		}
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Ciclo Aumentado"));
	}
}

void AFigura::CambiarDireccion()
{
	if(band)
	{
		SetActorLocation(FVector(0.0f, 0.0f, 160.0f));
		band = false;
	}
	else {
		SetActorLocation(FVector(0.0f, 0.0f, 160.0f));
		band = true;
	}
}


