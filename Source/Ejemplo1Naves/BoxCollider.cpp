// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxCollider.h"
#include "Shape.h"

void ABoxCollider::BeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("comieza el objeto"));
	UE_LOG(LogActor, Warning, TEXT("coienza el objeto"));

	OnActorBeginOverlap.AddDynamic(this, &ABoxCollider::colisionar);
}

void ABoxCollider::colisionar(AActor* objetoA, AActor* naveChoque)
{
	if (objetoA && naveChoque)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("hubo una colision "));

		UE_LOG(LogActor, Warning, TEXT("Hubo una colision entre %s y %s"), *objetoA->GetName(), *naveChoque->GetName());

		//1 muestra los nombres de los objetos que colisionaron
		//2 crear shapes en una posicion proxima a este objeto

		UWorld* const World = GetWorld();
		
		//World->SpawnActor<AShape>(en donde, que direccion);
		int CoorAleatoria = FMath::RandRange(100, 400);
		AShape* nuevoShape = World->SpawnActor<AShape>(objetoA->GetActorLocation() + FVector(CoorAleatoria, 100, 0), naveChoque->GetActorRotation());

		if (nave)
		{
			nave->addShape(nuevoShape);
		}
	}
}
