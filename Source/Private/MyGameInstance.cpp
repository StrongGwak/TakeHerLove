// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	// ActionStruct ������ ��� DT_Action�� �ҷ��´�.
	DT_ActionData = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/BluePrint/DataTable/DT_Action.DT_Action'"));

	// DT_Action DataTable�� ��� RowName�� �ҷ��� FName �迭�� �Ҵ��Ѵ�.
	TArray<FName> ActionNames = DT_ActionData->GetRowNames();

	// FName�� Key�� �ش� index�� Value�� ActionMap�� �����Ѵ�.
	// �� �� RowName�� ��ġ�� ���� Struct�� Actions �迭�� �߰��Ѵ�.
	for (int i = 0; i < ActionNames.Num(); i++) {
		ActionMap.Add(ActionNames[i], i);
		Actions.Add(*(DT_ActionData->FindRow<FActionStruct>(ActionNames[i], ActionNames[i].ToString())));
	}
}

void UMyGameInstance::IsShowOn(FName ActionName)
{
	// Level�� ��ġ�� InteractObject�� ActionName���� �ش� Action�� Ȱ��ȭ�Ѵ�.
	Actions[ActionMap[ActionName]].IsShow = true;
}

void UMyGameInstance::IsShowOff(FName ActionName)
{
	// Level�� ��ġ�� InteractObject�� ActionName���� �ش� Action�� ��Ȱ��ȭ�Ѵ�.
	Actions[ActionMap[ActionName]].IsShow = false;
}