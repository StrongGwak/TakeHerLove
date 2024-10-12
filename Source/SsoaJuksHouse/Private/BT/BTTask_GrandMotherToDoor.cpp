// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GrandMotherToDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_GrandMotherToDoor::UBTTask_GrandMotherToDoor()
{
	NodeName = "GrandMotherToDoor";
}

EBTNodeResult::Type UBTTask_GrandMotherToDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsGrandMotherRoomTalk"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGrandMotherBackDoor"), true);

	return EBTNodeResult::Succeeded;
}

