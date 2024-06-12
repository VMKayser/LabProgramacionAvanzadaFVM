// Fill out your copyright notice in the Description page of Project Settings.

#include "BoxDestruir.h"

#include "Kismet/GameplayStatics.h"

ABoxDestruir::ABoxDestruir()
{
    
    OnActorBeginOverlap.AddDynamic(this, &ABoxDestruir::OnOverlapBegin);

}


void ABoxDestruir::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    
    if (OtherActor && OtherActor != this)
    {

        TArray<AActor*> AllShapes;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShape::StaticClass(), AllShapes);

       
        for (AActor* Shape : AllShapes)
        {
            if (Shape)
            {
                Shape->Destroy();
            }
        }

    
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Shapes destruidos"));
    }
}