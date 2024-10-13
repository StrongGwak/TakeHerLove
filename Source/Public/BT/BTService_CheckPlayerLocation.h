// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_CheckPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UBTService_CheckPlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_CheckPlayerLocation();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnderComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	bool isFar;
	bool isMoreFar;
	float currentTime;
};
