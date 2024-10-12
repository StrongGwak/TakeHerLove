// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionStruct.h"
#include "ActionButton.generated.h"

DECLARE_DELEGATE_OneParam(FDele_Action, FActionStruct);

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UActionButton : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UButton* ActionButton = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UTextBlock* ActionName = nullptr;

	// 행동 구조체를 버튼 생성시 할당해야하기에 변수로 미리 생성
	UPROPERTY()
	FActionStruct ActionStruct;

	// 버튼을 눌렀을 때, 호출될 델리게이트에 등록할 함수
	UFUNCTION(BlueprintCallable)
	void ActionButtonCallback();

	// 델리게이트 함수
	FDele_Action Func_Action;

};
