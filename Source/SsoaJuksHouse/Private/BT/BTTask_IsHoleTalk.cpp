// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_IsHoleTalk.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"


UBTTask_IsHoleTalk::UBTTask_IsHoleTalk()
{
	NodeName = "DoorToHoleTalk";
}

EBTNodeResult::Type UBTTask_IsHoleTalk::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AMyCharacter* player = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	UTextBlock* TextBlock = Cast<UTextBlock>(player->HUDWidget->GetWidgetFromName(TEXT("AIText")));
	TextBlock->SetText(FText::FromString(TEXT("우리 집 구경시켜줄게 따라와")));
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}


	return EBTNodeResult::Succeeded;
}
