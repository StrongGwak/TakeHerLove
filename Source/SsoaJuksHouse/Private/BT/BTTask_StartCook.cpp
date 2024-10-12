// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_StartCook.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_StartCook::UBTTask_StartCook()
{
	NodeName = "StartCook";
}

EBTNodeResult::Type UBTTask_StartCook::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) 
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToCook"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsCook"), true);


	return EBTNodeResult::Succeeded;
}
