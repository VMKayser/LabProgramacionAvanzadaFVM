// Fill out your copyright notice in the Description page of Project Settings.


#include "CambiarMovimiento.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
ACambiarMovimiento::ACambiarMovimiento()
{

	OnActorBeginOverlap.AddDynamic(this, &ACambiarMovimiento::OnOverlapBegin);

}


void ACambiarMovimiento::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{

	if (OtherActor && OtherActor != this)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFigura::StaticClass(), FoundActors);
		for (AActor* Actor : FoundActors)
		{
			AFigura* Figuranew = Cast<AFigura>(Actor);
			if (Figuranew != nullptr)
			{
				Figuranew->CambiarDireccion();
				
			}
		}

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Shape cambio de direccion"));
	}
}

