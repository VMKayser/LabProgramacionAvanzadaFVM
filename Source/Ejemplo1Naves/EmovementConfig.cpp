#include "EMovementConfig.h"

// Sets default values
AEMovementConfig::AEMovementConfig()
{
	// Set this empty to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEMovementConfig::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEMovementConfig::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEMovementConfig::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
