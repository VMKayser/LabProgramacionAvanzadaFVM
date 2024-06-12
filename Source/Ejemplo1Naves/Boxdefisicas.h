// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Shape.h" // Asegúrate de incluir el archivo de encabezado de Shape si aún no está incluido
#include "Boxdefisicas.generated.h"
// Sets default values
/**
 *
 */
UCLASS()
class EJEMPLO1NAVES_API ABoxdefisicas : public ATriggerBox
{
    GENERATED_BODY()

public:
    // Constructor
    ABoxdefisicas();


protected:
    // Función para manejar el evento de inicio de superposición
    UFUNCTION()
    void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
  
};

