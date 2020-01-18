#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "FPossiblyRangedValue.generated.h"

/**
 * Stores a single float or a range of min, max floats,
 * useful for defining data-driven gameplay that requires a range of possible values.
 * 
 * For example: Diablo-style procedurally items that can roll between 10 - 50 Vitality.
*/

// TODO: Fix this m
// UENUM()
// enum EPossiblyRangedValueGetterPolicy
// {
//   NotRanged,
//   RandomInRange,
// };

USTRUCT(BlueprintType)
struct FPossiblyRangedValue
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Value;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool IsRanged;
  /** 
   * Controls how GetValue behaves,
   * returns Value if NotRanged,
   * else uses Min, Max to calculate what to return.
  */
  // UPROPERTY(EditAnywhere, BlueprintReadWrite)
  // EPossiblyRangedValueGetterPolicy GetterPolicy;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Min;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Max;

  // UFUNCTION()
  // float GetValue()
  // {
  //   if (GetterPolicy == EPossiblyRangedValueGetterPolicy::NotRanged);
  //   {
  //     return Value;
  //   } else if
  //   {
  //     return FMath::RandRange(Min, Max);
  //   }

  // }
};