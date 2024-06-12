// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ejemplo1NavesGameMode.generated.h"

UCLASS(MinimalAPI)
class AEjemplo1NavesGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEjemplo1NavesGameMode();
protected:
	virtual void BeginPlay() override;
};



