// Fill out your copyright notice in the Description page of Project Settings.



#include "BTTask_OpenDoor.h"
#include "Enemy.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "MyAIController.h"
#include "Misc/OutputDeviceNull.h"


UBTTask_OpenDoor::UBTTask_OpenDoor()
{
	NodeName = "OpenDoor";
}

EBTNodeResult::Type UBTTask_OpenDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemy* AiCharacter = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetCharacter());
	if (AiCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	FHitResult Hit;
	FVector StartTrace = AiCharacter->GetActorLocation();
	FVector EndTrace = StartTrace + (AiCharacter->GetActorForwardVector() * 300);
	DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Red, false, 5.0f);

	bool isHit = GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_GameTraceChannel3);
	if (isHit)
	{
		UPrimitiveComponent* NewHitComponent = Hit.GetComponent();
		AActor* HitActor = Hit.GetActor();
		if (HitActor->ActorHasTag("Door"))
		{
			FOutputDeviceNull ar;
			HitActor->CallFunctionByNameWithArguments(TEXT("OpenDoor"), ar, nullptr, true);
		}
	}

	return EBTNodeResult::Succeeded;
}
