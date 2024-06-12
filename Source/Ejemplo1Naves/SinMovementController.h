// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SinMovementController.generated.h"

UCLASS()
class EJEMPLO1NAVES_API ASinMovementController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASinMovementController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Movement Controller")
	float DeltaX;
	UPROPERTY(EditAnywhere, Category = "Movement Controller")
	float DeltaY;
	UPROPERTY(EditAnywhere, Category = "Movement Controller")
	float Amplitude;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void move(float DeltaTime);

};
