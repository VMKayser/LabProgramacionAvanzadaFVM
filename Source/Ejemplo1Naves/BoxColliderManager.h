// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Shape.h"
#include "BoxColliderManager.generated.h"

/**
 * 
 */
UCLASS()
class EJEMPLO1NAVES_API ABoxColliderManager: public ATriggerBox
{
    GENERATED_BODY()

public:
    // Constructor
    ABoxColliderManager();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Naves")
    TArray<AShape*> ListaDeNaves;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Naves")
    TArray<int32> MallasActual;


protected:
    // Función para manejar el evento de inicio de superposición
    int estadoProceso;
    bool MoverNave;
	bool Gravedad;
    void FormacionNavesEnemigas(int CantidadNaves,int NumeroDeFilas);
public:
   
    UFUNCTION()
    void colisionar(class AActor* objetoA, class AActor* objetoB);
    void CrearNavesEnemigas(FVector UbicacionInicial,int tipomalla);
    void SaltarShapes();
    void MoverObjetos(float DeltaTime);

    void EliminarObjetos();
    virtual void Tick(float DeltaTime) override;

};

