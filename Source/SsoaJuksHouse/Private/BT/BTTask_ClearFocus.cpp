// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearFocus.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "MyAIController.h"
#include "Enemy.h"


UBTTask_ClearFocus::UBTTask_ClearFocus()
{
	NodeName = "ClearFocus";
}

EBTNodeResult::Type UBTTask_ClearFocus::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemy* AiCharacter = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetCharacter());
	if (AiCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	OwnerComp.GetAIOwner()->ClearFocus(EAIFocusPriority::Gameplay);

	return EBTNodeResult::Succeeded;
}
