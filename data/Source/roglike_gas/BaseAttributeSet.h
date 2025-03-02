// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

/**
 * 
 */

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class ROGLIKE_GAS_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="BaseAttributeSet")
	FGameplayAttributeData HP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HP);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHP);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MP);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxMP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMP);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Strength);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStrength);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData Exprience;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Exprience);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Level);
	
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
