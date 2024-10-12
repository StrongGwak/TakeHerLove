// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UActionButton::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ActionButton = Cast<UButton>(GetWidgetFromName(TEXT("ActionButton")));

	ActionName = Cast<UTextBlock>(GetWidgetFromName(TEXT("ActionName")));

	ActionButton->OnClicked.AddDynamic(this, &UActionButton::ActionButtonCallback);
}

void UActionButton::ActionButtonCallback()
{
	if (Func_Action.IsBound() == true) {
		Func_Action.Execute(ActionStruct);
	}
	
}
