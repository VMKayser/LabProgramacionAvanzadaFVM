// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveController.h"

// Sets default values
AWaveController::AWaveController()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaveController::BeginPlay()
{
    Super::BeginPlay();
    InitialLocation = GetActorLocation();

}

void AWaveController::UpdateWaveDisplacement(float DeltaTime)
{
    // Calculate the wave displacement
    float Time = GetWorld()->GetTimeSeconds();
    float Displacement = Amplitude * FMath::Sin(2.0f * PI * Frequency * Time + PhaseShift);

    // Apply the displacement to the actor's location
    FVector NewLocation = InitialLocation + FVector(0.0f, Displacement, 0.0f);
    SetActorLocation(NewLocation);
}

// Called every frame
void AWaveController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateWaveDisplacement(DeltaTime);
}

