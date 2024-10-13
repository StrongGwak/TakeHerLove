// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GrandMotherToGirl.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_GrandMotherToGirl::UBTTask_GrandMotherToGirl()
{
	NodeName = "GrandMotherToGirl";
}

EBTNodeResult::Type UBTTask_GrandMotherToGirl::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGrandMotherBackDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGirlDoor"), true);

	return EBTNodeResult::Succeeded;
}
