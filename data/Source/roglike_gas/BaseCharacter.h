// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayEffectTypes.h"
#include "BaseGameplayAbility.h"
#include "HealthInterface.h"
#include "BaseCharacter.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangeEvent, float, NewValue);
UCLASS()
class ROGLIKE_GAS_API ABaseCharacter : public ACharacter, public IHealthInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintAssignable,Category="Ability")
	FOnHealthChangeEvent HPChangeEvent;

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHealthChangeEvent MPChangeEvent;

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHealthChangeEvent StrengthChangeEvent;

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHealthChangeEvent LevelChangeEvent;

	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHealthChangeEvent ExprienceChangeEvent;

	void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);

	void OnMPAttributeChanged(const FOnAttributeChangeData& Data);

	void OnStrAttributeChanged(const FOnAttributeChangeData& Data);

	void OnLevelAttributeChanged(const FOnAttributeChangeData& Data);

	void OnExprienceAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintCallable,Category = "BaseCharacter")
	FGameplayAbilityInfo GameplayAbilityInfo(TSubclassOf<UBaseGameplayAbility>AbilityClass,int level);

	virtual void OnDeath_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void DealthExecute();
};
