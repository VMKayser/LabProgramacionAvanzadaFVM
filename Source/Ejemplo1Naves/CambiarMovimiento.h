// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Figura.h"
#include "CambiarMovimiento.generated.h"

/**
 * 
 */
UCLASS()
class EJEMPLO1NAVES_API ACambiarMovimiento : public ATriggerBox
{
	GENERATED_BODY()
public:
	// Constructor
	ACambiarMovimiento();
protected:
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
};
