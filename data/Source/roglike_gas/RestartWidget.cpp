// Fill out your copyright notice in the Description page of Project Settings.


#include "RestartWidget.h"

#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "GasPlayerController.h"
#include "BaseCharacter.h"

void URestartWidget::OnRestartClicked() {
	UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
	AGasPlayerController* PlayerController = Cast<AGasPlayerController>(GetOwningPlayer());
	if (PlayerController != nullptr) {
		PlayerController->HideRestartWidget();
	}
}

void URestartWidget::NativeOnInitialized() {
	Super::NativeOnInitialized();
	if (RestartButton != nullptr) {
		RestartButton->OnClicked.AddDynamic(this, &URestartWidget::OnRestartClicked);
	}
	if (ExitButton != nullptr) {
		ExitButton->OnClicked.AddDynamic(this, &URestartWidget::OnExitClicked);
	}
}

void URestartWidget::OnExitClicked() {
	if (Cast<ABaseCharacter>(GetOwningPlayerPawn()) != nullptr)
	{
		UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
	}
}