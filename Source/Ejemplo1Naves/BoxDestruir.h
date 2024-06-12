// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Shape.h" // Asegúrate de incluir el archivo de encabezado de Shape si aún no está incluido
#include "BoxDestruir.generated.h"

/**
 *
 */
UCLASS()
class EJEMPLO1NAVES_API ABoxDestruir : public ATriggerBox
{
    GENERATED_BODY()

public:
    // Constructor
    ABoxDestruir();
   
protected:
    // Función para manejar el evento de inicio de superposición
    UFUNCTION()
    void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
};
