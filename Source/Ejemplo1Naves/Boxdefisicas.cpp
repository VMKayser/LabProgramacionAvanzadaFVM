// Fill out your copyright notice in the Description page of Project Settings.


#include "Boxdefisicas.h"

#include "Kismet/GameplayStatics.h"
ABoxdefisicas::ABoxdefisicas()
{

    OnActorBeginOverlap.AddDynamic(this, &ABoxdefisicas::OnOverlapBegin);

}


void ABoxdefisicas::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{

    if (OtherActor && OtherActor != this)
    {
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShape::StaticClass(), FoundActors);
		for (AActor* Actor : FoundActors)
		{
			AShape* Shapenew = Cast<AShape>(Actor);
			if (Shapenew != nullptr)
			{
				Shapenew->saltar();
			}
		}

        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Shapes lanzados"));
    }
}