// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GasPlayerController.h"
#include "HealthInterface.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	UAbilitySystemComponent* MyAbilityComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	if (MyAbilityComponent) {
		MyAbilityComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetHPAttribute()).AddUObject(this,&ABaseCharacter::OnHealthAttributeChanged);
		MyAbilityComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetMPAttribute()).AddUObject(this, &ABaseCharacter::OnMPAttributeChanged);
		MyAbilityComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetStrengthAttribute()).AddUObject(this, &ABaseCharacter::OnStrAttributeChanged);
		MyAbilityComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetLevelAttribute()).AddUObject(this, &ABaseCharacter::OnLevelAttributeChanged);
		MyAbilityComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetExprienceAttribute()).AddUObject(this, &ABaseCharacter::OnExprienceAttributeChanged);
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	HPChangeEvent.Broadcast(Data.NewValue);
}

void ABaseCharacter::OnMPAttributeChanged(const FOnAttributeChangeData& Data)
{
	MPChangeEvent.Broadcast(Data.NewValue);
}

void ABaseCharacter::OnStrAttributeChanged(const FOnAttributeChangeData& Data)
{
	StrengthChangeEvent.Broadcast(Data.NewValue);
}

void ABaseCharacter::OnLevelAttributeChanged(const FOnAttributeChangeData& Data)
{
	LevelChangeEvent.Broadcast(Data.NewValue);
}

void ABaseCharacter::OnExprienceAttributeChanged(const FOnAttributeChangeData& Data)
{
	ExprienceChangeEvent.Broadcast(Data.NewValue);
}

FGameplayAbilityInfo ABaseCharacter::GameplayAbilityInfo(TSubclassOf<UBaseGameplayAbility> AbilityClass, int level)
{
	UAbilitySystemComponent* MAS = this->FindComponentByClass<UAbilitySystemComponent>();
	UBaseGameplayAbility* AbI = AbilityClass->GetDefaultObject<UBaseGameplayAbility>();
	if (MAS && AbI) 
	{
		return AbI->GetAbilityInfo(level);
	}
	return FGameplayAbilityInfo();
}

void ABaseCharacter::OnDeath_Implementation()
{
	AGasPlayerController* PlayerController = Cast<AGasPlayerController>(GetController());
	if (PlayerController != nullptr) {
		PlayerController->ShowRestartWidget();
	}
}

void ABaseCharacter::DealthExecute()
{
	if (Implements<UHealthInterface>())
	{
		IHealthInterface::Execute_OnDeath(this);
	}
}

