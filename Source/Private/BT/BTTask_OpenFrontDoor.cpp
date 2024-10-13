// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_OpenFrontDoor.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyAIController.h"
#include "Enemy.h"
#include "Misc/OutputDeviceNull.h"
#include "kismet/GameplayStatics.h"
#include "Engine/GameEngine.h"

UBTTask_OpenFrontDoor::UBTTask_OpenFrontDoor()
{
	NodeName = "OpenFrontDoor";
}

EBTNodeResult::Type UBTTask_OpenFrontDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemy* AiCharacter = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetCharacter());

	if (AiCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AActor* FrontDoor = Cast<AActor>(BlackboardComp->GetValueAsObject(TEXT("FrontDoor")));

	FOutputDeviceNull ar;
	FrontDoor->CallFunctionByNameWithArguments(TEXT("OpenDoor"), ar, nullptr, true);

	return EBTNodeResult::Succeeded;

}
