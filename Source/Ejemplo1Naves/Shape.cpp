// Fill out your copyright notice in the Description page of Project Settings.


#include "Shape.h"


TArray<UStaticMesh*> AShape::MeshArray;
int AShape::nroDisfraces = 4;

// Sets default values
AShape::AShape()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Controlador"));
	RootComponent = Root;

	malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla_Mesh"));
	malla->AttachTo(Root);
	impulso = 80000;
	
	
	velocity = 100.0f;
	direccion = 1;

	
	SigMovimientoY = 5.0f;
	bMovimientoDerecha = true;
	

}
void AShape::fisicas() {
	malla->SetSimulatePhysics(true);
	
}

void AShape::saltar() {
	FVector NNSpawnLocation(0.0f, 0.0f, 160.0f);
	malla->SetSimulatePhysics(true);
	if (!saltando) {
		malla->AddImpulse(FVector::UpVector * impulso);
		saltando = true;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("voy a saltar "));
	}
	}

void AShape::AsignarMalla(int valormalla)
{
	
	if (MeshArray.IsValidIndex(valormalla))
	{
		UStaticMesh* SelectedMesh = MeshArray[valormalla];
		if (SelectedMesh)
		{
			UE_LOG(LogActor, Warning, TEXT("Malla asignada"));
			malla->SetStaticMesh(SelectedMesh);
		}
		else
		{
			UE_LOG(LogActor, Warning, TEXT("Malla seleccionada no es válida"));
		}
	}
	else
	{
		UE_LOG(LogActor, Warning, TEXT("Índice fuera de rango"));
	}

}

// Called when the game starts or when spawned
void AShape::BeginPlay()
{
	Super::BeginPlay();

	if (MeshArray.Num() == 0) {
		UStaticMesh* disfraz3D_1 = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("/Game/StarterContent/Shapes/Shape_Cube")));
		UStaticMesh* disfraz3D_2 = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("/Game/StarterContent/Shapes/Shape_Cylinder")));
		UStaticMesh* disfraz3D_3 = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("/Game/StarterContent/Shapes/Shape_Sphere")));
		UStaticMesh* disfraz3D_4 = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("/Game/StarterContent/Shapes/Shape_Tube")));

		MeshArray.Add(disfraz3D_1);
		MeshArray.Add(disfraz3D_2);
		MeshArray.Add(disfraz3D_3);
		MeshArray.Add(disfraz3D_4);
	}

	// Asignar malla aleatoria si no se ha asignado explícitamente
	if (!mallaexiste) {
		int32 RandomIndex = FMath::RandRange(0, MeshArray.Num() - 1);
		AsignarMalla(RandomIndex);
	}

}
	//InitialLocation = GetActorLocation();

	//este segmeneto permite cargar la malla y asignlar al objeto




// Called every frame
void AShape::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//mover(DeltaTime);
//	//move(DeltaTime);
//	MoverIntercalado(DeltaTime);
//	posicion = GetActorLocation();
//}
}

void AShape::mover(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation;
	float y = FMath::Sin(90);
	//NewLocation = CurrentLocation + FVector::ForwardVector * velocity * DeltaTime; //(1,0,0)*50 = (50,0,0)
	switch (direccion)
	{
	case 1://NOrte
		NewLocation = CurrentLocation + FVector::BackwardVector * velocity * DeltaTime; //(1,0,0)*50 = (50,0,0)
		break;

	case 4://sur
		NewLocation = CurrentLocation + FVector::ForwardVector * velocity * DeltaTime; //(1,0,0)*50 = (50,0,0)
		break;
	}




	SetActorLocation(NewLocation);
}


void AShape::move(float DeltaTime)
{
	//UE_LOG(LogActor, Warning, TEXT("Position of Shape %s"), *this->GetActorLocation().ToString());

	float x, y;
	FVector currentLocation = GetActorLocation();
	// xActual, yActual
	//  xActual + x      yActual + y
	x = currentLocation.X + deltaX;
	y = currentLocation.Y + amplitude * FMath::Sin(x * frecuency);

	FVector newLocation;
	newLocation.X = x;
	newLocation.Y = y;
	newLocation.Z = currentLocation.Z;

	SetActorLocation(newLocation);
}

void AShape::MoverConImpulso(float DeltaTime)
{
	
	
		// Calcula el vector de impulso deseado (en este caso, hacia la izquierda)
		FVector ImpulseVector = FVector(-1.0f, 0.0f, 0.0f) * 3000.0f;

		// Aplica el impulso al centro de masa de la nave
		malla->AddImpulse(ImpulseVector);

	
	
}

void AShape::MoverIntercalado(float DeltaTime)
{
	auto NENuevaPosicion = GetActorLocation() + FVector(0.0f,bMovimientoDerecha ? SigMovimientoY : -SigMovimientoY, 0.0f);

	//Actualiza la posición del objeto
	SetActorLocation(NENuevaPosicion);
	//FVector Movimiento = FVector(bMovimientoArriba ? MovimientoSig : -MovimientoSig,
		//bMovimientoArriba ? MovimientoSig : -MovimientoSig, 0.0f);
	
	if (bMovimientoDerecha && GetActorLocation().Y >= 1000.0f)
	{
		bMovimientoDerecha = false;
	}
	else if (!bMovimientoDerecha && GetActorLocation().Y <= -1000.0f)
	{
		bMovimientoDerecha = true;
	}


}

void AShape::CambiarDireccion()
{
	if (bMovimientoDerecha)
	{
		bMovimientoDerecha = false;
	}
	else if (!bMovimientoDerecha)
	{
		bMovimientoDerecha = true;
	}
}
