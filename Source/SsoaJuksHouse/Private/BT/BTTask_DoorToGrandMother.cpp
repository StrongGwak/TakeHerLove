// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DoorToGrandMother.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_DoorToGrandMother::UBTTask_DoorToGrandMother()
{
	NodeName = "DoorToGrandMother";
}

EBTNodeResult::Type UBTTask_DoorToGrandMother::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGrandMotherDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGrandMother"), true);

	return EBTNodeResult::Succeeded;
}
