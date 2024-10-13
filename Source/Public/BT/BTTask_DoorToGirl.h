// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_DoorToGirl.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UBTTask_DoorToGirl : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_DoorToGirl();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};