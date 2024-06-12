// Fill out your copyright notice in the Description page of Project Settings.


#include "SinMovementController.h"

// Sets default values
ASinMovementController::ASinMovementController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASinMovementController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASinMovementController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASinMovementController::move(float DeltaTime)
{
	UE_LOG(LogActor, Warning, TEXT("Position of Actor %s"), *this->GetActorLocation().ToString());

	float x, y;
	FVector currentLocation = GetActorLocation();
	// xActual, yActual
	//  xActual + x      yActual + y
	x = currentLocation.X + DeltaX;
	y = currentLocation.Y + Amplitude * FMath::Sin(x);

	FVector newLocation;
	newLocation.X = x;
	newLocation.Y = y;

	SetActorLocation(newLocation);
}

