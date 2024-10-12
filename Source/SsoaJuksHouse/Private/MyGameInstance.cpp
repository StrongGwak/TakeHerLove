// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	// ActionStruct 정보가 담긴 DT_Action을 불러온다.
	DT_ActionData = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/BluePrint/DataTable/DT_Action.DT_Action'"));

	// DT_Action DataTable의 모든 RowName을 불러와 FName 배열에 할당한다.
	TArray<FName> ActionNames = DT_ActionData->GetRowNames();

	// FName을 Key로 해당 index를 Value로 ActionMap에 저장한다.
	// 그 후 RowName과 일치한 행의 Struct를 Actions 배열에 추가한다.
	for (int i = 0; i < ActionNames.Num(); i++) {
		ActionMap.Add(ActionNames[i], i);
		Actions.Add(*(DT_ActionData->FindRow<FActionStruct>(ActionNames[i], ActionNames[i].ToString())));
	}
}

void UMyGameInstance::IsShowOn(FName ActionName)
{
	// Level에 배치된 InteractObject가 ActionName으로 해당 Action을 활성화한다.
	Actions[ActionMap[ActionName]].IsShow = true;
}

void UMyGameInstance::IsShowOff(FName ActionName)
{
	// Level에 배치된 InteractObject가 ActionName으로 해당 Action을 비활성화한다.
	Actions[ActionMap[ActionName]].IsShow = false;
}