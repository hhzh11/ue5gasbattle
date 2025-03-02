// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GasPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ROGLIKE_GAS_API AGasPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class URestartWidget> BP_RestartWidget;
	void ShowRestartWidget();
	void HideRestartWidget();
private:
	class URestartWidget* RestartWidget;
};
