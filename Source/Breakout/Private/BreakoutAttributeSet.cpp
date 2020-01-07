// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakoutAttributeSet.h"

void UBreakoutAttributeSet::PreAttributeChange(const FGameplayAttribute &Attribute, float &NewValue)
{
  Super::PreAttributeChange(Attribute, NewValue);
}

void UBreakoutAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData &Data)
{
  Super::PostGameplayEffectExecute(Data);
}