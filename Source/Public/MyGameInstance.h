// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ActionStruct.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// Init �Լ��� ������ ���۵ǰ� ���� ���� ȣ��ȴ�.
	virtual void Init() override;

	// �ൿ ����ü�� �����ϱ����� ActuonStruct �迭
	// �ش� �迭�� ������ Interact ������Ʈ���� �����ؾ��ϱ� ������ public ���� �����Ѵ�.
	UPROPERTY()
	TArray<FActionStruct> Actions;

	// Level�� �ִ� Interact Object���� IsShow�� On/Off �� �� �ִ� �Լ�
	UFUNCTION(BlueprintCallable)
	void IsShowOn(FName ActionName);

	UFUNCTION(BlueprintCallable)
	void IsShowOff(FName ActionName);

private:
	// Action Struct�� ������ִ� DataTable
	UPROPERTY()
	UDataTable* DT_ActionData = nullptr;

	// Action�� Name���� �ĺ��ϱ� ���� Map
	UPROPERTY()
	TMap<FName, int32> ActionMap;
	
};
