// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Board.h"
#include "BreakoutController.generated.h"

/**
 * 
 */
UCLASS()
class BREAKOUT_API ABreakoutController : public APlayerController
{
	GENERATED_BODY()

public:
	ABreakoutController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ABoard> BoardToSpawn;

	UPROPERTY(BlueprintReadOnly)
	ABoard *Board;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, ClampMax = 1.0f))
	float BoardSpawnScreenWidth{0.5f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, ClampMax = 1.0f))
	float BoardSpawnScreenHeight{0.95f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 10.f, ClampMax = 2000.0f))
	float MovementSpeed{100.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 1.0f, ClampMax = 2000.0f))
	/**
	 * For improved feel, how strong the board starts moving after the direction changes
	 */
	float DirectionChangedImpulseStrength{5.0f};

	void Fire();

protected:
	void MoveRight(const float Value);
};
