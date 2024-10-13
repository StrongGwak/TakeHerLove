// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_StorageTalk.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UBTTask_StorageTalk : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_StorageTalk();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};