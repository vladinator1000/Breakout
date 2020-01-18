#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "FPossiblyRangedValue.h"
#include "Abilities/GameplayAbility.h"
#include "FAbilityWithAttributes.generated.h"

/**
 * Allows reuse of gameplay abilities in a data-driven way. 
 * For example, a Melee Attack with with 1 Damage and 2 Speed.
*/
USTRUCT(BlueprintType)
struct FAbilityWithAttributes
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UGameplayAbility *Ability;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TMap<FGameplayAttribute, FPossiblyRangedValue> Attributes;

};