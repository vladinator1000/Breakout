// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BreakoutAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)         \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)               \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)               \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class BREAKOUT_API UBreakoutAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	virtual void PreAttributeChange(const FGameplayAttribute &Attribute, float &NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData &Data) override;

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBreakoutAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UBreakoutAttributeSet, Damage)
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UBreakoutAttributeSet, Speed)
};
