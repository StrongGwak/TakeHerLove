// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_BalconyTalk.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTaskNode_BalconyTalk::UBTTaskNode_BalconyTalk()
{
	NodeName = "BalconyTalk";
}

EBTNodeResult::Type UBTTaskNode_BalconyTalk::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToBalcony"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsBalconyTalk"), true);

	return EBTNodeResult::Succeeded;
}
