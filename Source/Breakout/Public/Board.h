// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Ball.h"
#include "DA_Ball.h"
#include "Abilities/BreakoutAttributeSet.h"
#include "Board.generated.h"

UCLASS()
class BREAKOUT_API ABoard : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoard();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent *StaticMeshComponent;

	virtual void BeginPlay() override;

	void GrabBall(ABall *Ball);
	void LaunchBalls();
	TArray<ABall *> Balls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDA_Ball *DefaultBallAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BallSpawnDistance{100.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 1.0f, ClampMax = 2000.0f))
	float BallLaunchSpeed{200.0f};

	UAbilitySystemComponent *GetAbilitySystemComponent() const override;

protected:
	/** The component used to handle ability system interactions */
	UPROPERTY()
	UAbilitySystemComponent *AbilitySystemComponent;

	/** List of attributes modified by the ability system */
	UPROPERTY()
	UBreakoutAttributeSet *AttributeSet;
};
