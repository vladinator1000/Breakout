#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "FGameplayAttributeValue.generated.h"

USTRUCT(BlueprintType)
struct FGameplayAttributeValue
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Value;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool IsRanged;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Min;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Max;
};