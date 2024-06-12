// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shape.h"
#include "Figura.generated.h"

UCLASS()
class EJEMPLO1NAVES_API AFigura : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFigura();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Arma, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mallaFigura;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int numerociclos;
	float velocidad;
	bool MovimientoDerecha;
	bool MovimientoArriba;
	TArray<AShape*> Objetos;
	FVector UbicacionInicial;
	FVector UbicacionFinal;
	bool band;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void crearobjetos(int numobj);
	void caerobjetos(int numobj);
	void MoverDiagonal(float DeltaTime);
	void CambiarDireccion();

};
