// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionButton.h"
#include "MyGameInstance.h"
#include "ActionWidget.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UActionWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	virtual void NativeOnInitialized();

	UPROPERTY()
	UDataTable* DT_ActionData = nullptr;

	UPROPERTY()
	UMyGameInstance* MyGameInstance = nullptr;

	UPROPERTY()
	TArray<FActionStruct> ActionArray;

public:
	UPROPERTY()
	class UActionButton* button = nullptr;

	UPROPERTY()
	TArray<UActionButton*> Buttons;
	
};
