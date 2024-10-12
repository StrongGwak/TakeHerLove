// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GirlToBalconyDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_GirlToBalconyDoor::UBTTask_GirlToBalconyDoor()
{
	NodeName = "GirlToBalconyDoor";
}

EBTNodeResult::Type UBTTask_GirlToBalconyDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGirlBackDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToBalconyDoor"), true);

	return EBTNodeResult::Succeeded;
}

