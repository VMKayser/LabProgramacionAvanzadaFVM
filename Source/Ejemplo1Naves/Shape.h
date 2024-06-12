// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shape.generated.h"


UENUM(BlueprintType)
enum class ShapeDirection :uint8
{
	Arriba,
	Abajo,
	Izquierda,
	Derecha
};

UCLASS()
class EJEMPLO1NAVES_API AShape : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	USceneComponent* Root;
	UStaticMeshComponent* AShape::GetMeshComponent() const
	{
		return malla;
	}
	UPROPERTY(EditAnyWhere)
	UStaticMeshComponent* malla;
	// Sets default values for this actor's properties
	AShape();
	void MoverConImpulso(float DeltaTime);
protected:
	UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	float velocity;

	UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	int direccion; //1 norte, 2 este, 3 oeste, 4 sur
	UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	float damageLevel;
	bool saltando;


	UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	float deltaX;
	UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	float amplitude;
	UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	float frecuency;
	UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	float impulso;
	FVector posicion;

	UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	ShapeDirection direction = ShapeDirection::Abajo;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UPROPERTY(EditAnywhere, Category = "Nave Enemiga")

	//UPROPERTY(EditAnywhere, Category = "Nave Enemiga")
	//EDirections dir = EDirections::North;

public:
	// Called every frame
	void AsignarMalla(int valormalla);
	virtual void Tick(float DeltaTime) override;
	void saltar();
	void mover(float DeltaTime);
	void move(float DeltaTime);
	void fisicas();
	static TArray<UStaticMesh*> MeshArray;
	bool bMovimientoDerecha;
	float SigMovimientoY;
	void MoverIntercalado(float DeltaTime);
	void CambiarDireccion();
private:
	
	static int nroDisfraces;
	FVector InitialLocation;
	bool mallaexiste;



};


