// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DoorToCook.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_DoorToCook::UBTTask_DoorToCook()
{
	NodeName = "DoorToCook";
}

EBTNodeResult::Type UBTTask_DoorToCook::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) 
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToCookDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToCook"), true);

	return EBTNodeResult::Succeeded;
}
