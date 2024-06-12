// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "shapeExamen.generated.h"

UCLASS()
class EJEMPLO1NAVES_API AshapeExamen : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AshapeExamen();
	USceneComponent* Root;
	UStaticMeshComponent* AshapeExamen::GetMeshComponent() const
	{
		return malla;
	}
	UPROPERTY(EditAnyWhere)
	UStaticMeshComponent* malla;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
