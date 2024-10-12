// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FarherToGrandMotherDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FarherToGrandMotherDoor::UBTTask_FarherToGrandMotherDoor()
{
	NodeName = "FarherToGrandMotherDoor";
}

EBTNodeResult::Type UBTTask_FarherToGrandMotherDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToFatherBackDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGrandMotherDoor"), true);

	return EBTNodeResult::Succeeded;
}

