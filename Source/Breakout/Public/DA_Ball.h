// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Abilities/FPossiblyRangedValue.h"
#include "DA_Ball.generated.h"

UCLASS()
class BREAKOUT_API UDA_Ball : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> BallActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTagContainer Tags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayAttribute, FPossiblyRangedValue> Attributes;
};
