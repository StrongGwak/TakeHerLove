// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_GirlRoomTalk.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UBTTaskNode_GirlRoomTalk : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTaskNode_GirlRoomTalk();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};
