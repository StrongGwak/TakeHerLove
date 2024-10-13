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
	// Init 함수는 게임이 시작되고 가장 먼저 호출된다.
	virtual void Init() override;

	// 행동 구조체를 저장하기위한 ActuonStruct 배열
	// 해당 배열을 레벨의 Interact 오브젝트들이 접근해야하기 때문에 public 으로 선언한다.
	UPROPERTY()
	TArray<FActionStruct> Actions;

	// Level에 있는 Interact Object들이 IsShow를 On/Off 할 수 있는 함수
	UFUNCTION(BlueprintCallable)
	void IsShowOn(FName ActionName);

	UFUNCTION(BlueprintCallable)
	void IsShowOff(FName ActionName);

private:
	// Action Struct가 저장돼있는 DataTable
	UPROPERTY()
	UDataTable* DT_ActionData = nullptr;

	// Action을 Name으로 식별하기 위한 Map
	UPROPERTY()
	TMap<FName, int32> ActionMap;
	
};
