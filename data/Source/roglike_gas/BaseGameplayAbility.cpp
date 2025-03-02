// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameplayAbility.h"

FGameplayAbilityInfo::FGameplayAbilityInfo() :
	CD(0),
	CostType(ECostType::MP),
	CostValue(0),
	iconMaterial(nullptr),
	AbilityClass(nullptr)
{

}

FGameplayAbilityInfo::FGameplayAbilityInfo(float CD, ECostType CostType, float CostValue,UMaterialInstance* iconMaterial, TSubclassOf<UBaseGameplayAbility> AbilityClass):
	CD(CD),
	CostType(CostType),
	CostValue(CostValue),
	iconMaterial(iconMaterial),
	AbilityClass(AbilityClass)
{
}

FGameplayAbilityInfo UBaseGameplayAbility::GetAbilityInfo(int level)
{
	UGameplayEffect* CDEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffectt = GetCostGameplayEffect();
	float CD = 0;
	float CostValue = 0;
	ECostType CostType = ECostType::MP;
	if (CDEffect && CostEffectt)
	{
		CDEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(level, CD);
		if (CostEffectt->Modifiers.Num() > 0) 
		{
			FGameplayModifierInfo CosteffectModifierInfo = CostEffectt->Modifiers[0];
			CosteffectModifierInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(level, CostValue);
			FString CostTypeName = CosteffectModifierInfo.Attribute.AttributeName;
			if (CostTypeName == "HP")
			{
				CostType = ECostType::HP;
			}
			if (CostTypeName == "MP")
			{
				CostType = ECostType::MP;
			}
			if (CostTypeName == "HP")
			{
				CostType = ECostType::Strength;
			}
			return FGameplayAbilityInfo(CD,CostType,CostValue,iconMaterial,GetClass());
		}
	}

	return FGameplayAbilityInfo();
}
