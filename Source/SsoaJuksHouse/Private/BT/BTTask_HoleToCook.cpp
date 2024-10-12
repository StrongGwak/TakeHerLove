// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_HoleToCook.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_HoleToCook::UBTTask_HoleToCook()
{
	NodeName = "HoleToCook";
}

EBTNodeResult::Type UBTTask_HoleToCook::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToHole"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToCookDoor"), true);

	return EBTNodeResult::Succeeded;
}
