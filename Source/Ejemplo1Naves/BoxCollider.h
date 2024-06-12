// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/StaticMeshComponent.h"

#include "Ejemplo1NavesPawn.h"
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "BoxCollider.generated.h"

/**
 *
 */
UCLASS()
class EJEMPLO1NAVES_API ABoxCollider : public ATriggerBox
{
	GENERATED_BODY()
public:
	virtual void BeginPlay();
	UFUNCTION()
	void colisionar(class AActor* objetoA, class AActor* objetoB);

	UPROPERTY(EditAnyWhere)
	AEjemplo1NavesPawn* nave;

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("comieza el objeto"));
};