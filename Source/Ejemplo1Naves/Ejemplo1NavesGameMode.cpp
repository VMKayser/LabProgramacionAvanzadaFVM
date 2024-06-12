// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ejemplo1NavesGameMode.h"
#include "Ejemplo1NavesPawn.h"
#include "BoxColliderManager.h"

AEjemplo1NavesGameMode::AEjemplo1NavesGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AEjemplo1NavesPawn::StaticClass();
}


void AEjemplo1NavesGameMode::BeginPlay() {
	
	
	Super::BeginPlay();
	//spawnear el box collider manager en 0,0,0 con rotacion 0
	GetWorld()->SpawnActor<ABoxColliderManager>(FVector(-810.0f, -150.0f, 214.0f), FRotator(0.0f, 0.0f, 0.0f));

}
