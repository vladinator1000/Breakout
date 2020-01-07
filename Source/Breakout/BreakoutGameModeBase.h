// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DA_Block.h"
#include "BreakoutGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BREAKOUT_API ABreakoutGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	FTimerHandle CheckViewportHandle;
	virtual void HandleStartingNewPlayer_Implementation(APlayerController *NewPlayer) override;

public:
	void SpawnBlocks();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block Spawning", meta = (ShortTooltip = "The plane on which to spawn everything."))
	float SpawnZHeight{300.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block Spawning", meta = (ShortTooltip = "How far apart to spawn blocks"))
	FVector2D BlockPadding{FVector2D(50.0f, 25.0f)};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block Spawning")
	int32 Rows{7};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block Spawning")
	int32 Columns{7};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block Spawning")
	FVector SpawnOrigin{FVector(500.0f, -550.0f, SpawnZHeight)};

	UPROPERTY(BlueprintReadOnly)
	class ABreakoutController *Controller;

protected:
	ABreakoutGameModeBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block Spawning")
	TArray<UDA_Block *> BlockDataAssets;
};
