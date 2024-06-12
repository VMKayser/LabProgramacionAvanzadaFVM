// Fill out your copyright notice in the Description page of Project Settings.


#include "shapeExamen.h"

// Sets default values
AshapeExamen::AshapeExamen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Controlador"));
	RootComponent = Root;

	malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla_Mesh"));
	malla->AttachTo(Root);

}

// Called when the game starts or when spawned
void AshapeExamen::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AshapeExamen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

