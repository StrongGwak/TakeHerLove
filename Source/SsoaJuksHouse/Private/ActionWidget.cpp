// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionWidget.h"
#include "ActionButton.h"
#include "ActionStruct.h"
#include "MyGameInstance.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UActionWidget::NativeOnInitialized()
{
	// GameInstance에 접근하여 ActionStruct 배열을 복사한다.
	MyGameInstance = Cast<UMyGameInstance>(GetGameInstance());
	ActionArray = MyGameInstance->Actions;

	int ActionCount = 1;
	for (int i = 0; i < ActionArray.Num(); i++) {
		if (ActionArray[i].IsShow) {
			FString ButtonName = FString::Printf(TEXT("ActionButton%d"), ActionCount++);
			FName path = FName(*ButtonName);
			button = Cast<UActionButton>(GetWidgetFromName(path));
			button->ActionStruct = ActionArray[i];
			button->ActionName->SetText(FText::FromString(ActionArray[i].ActionName));
			button->RenderOpacity = 1;
			Buttons.Add(button);
		}
	}
	
	float Radius = 300.0f;
	float Angle = 360.0f / (ActionCount - 1);

	for (int i = 0; i < ActionCount - 1; i++) {
		float Radians = FMath::DegreesToRadians(Angle * i);
		float X = Radius * FMath::Cos(Radians);
		float Y = Radius * FMath::Sin(Radians);
		Buttons[i]->SetRenderTranslation(FVector2D(X, Y));
	}
	
}
