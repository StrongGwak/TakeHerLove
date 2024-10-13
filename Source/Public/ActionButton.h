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

	// �ൿ ����ü�� ��ư ������ �Ҵ��ؾ��ϱ⿡ ������ �̸� ����
	UPROPERTY()
	FActionStruct ActionStruct;

	// ��ư�� ������ ��, ȣ��� ��������Ʈ�� ����� �Լ�
	UFUNCTION(BlueprintCallable)
	void ActionButtonCallback();

	// ��������Ʈ �Լ�
	FDele_Action Func_Action;

};
