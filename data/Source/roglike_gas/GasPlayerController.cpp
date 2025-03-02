// Fill out your copyright notice in the Description page of Project Settings.


#include "GasPlayerController.h"

#include "RestartWidget.h"

void AGasPlayerController::ShowRestartWidget() {
	if (BP_RestartWidget == nullptr) {
		return;
	}
	SetPause(true);
	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
	RestartWidget = CreateWidget<URestartWidget>(this, BP_RestartWidget);
	RestartWidget->AddToViewport();
}

void AGasPlayerController::HideRestartWidget() {
	if (BP_RestartWidget == nullptr) {
		return;
	}
	RestartWidget->RemoveFromParent();
	RestartWidget->Destruct();
	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}