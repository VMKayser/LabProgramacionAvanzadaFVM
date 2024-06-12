// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "WaveController.generated.h"

UCLASS()
class EJEMPLO1NAVES_API AWaveController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWaveController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Wave Movement")
	float Amplitude = 100.0f; // Adjust as needed
	UPROPERTY(EditAnywhere, Category = "Wave Movement")
	float Frequency = 1.0f; // Adjust as needed
	UPROPERTY(EditAnywhere, Category = "Wave Movement")
	float PhaseShift = 0.0f; // Adjust as needed

	FVector InitialLocation;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateWaveDisplacement(float DeltaTime);

};
