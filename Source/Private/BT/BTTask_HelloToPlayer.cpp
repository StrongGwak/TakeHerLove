// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_HelloToPlayer.h"
#include "MyAIController.h"
#include "Enemy.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

UBTTask_HelloToPlayer::UBTTask_HelloToPlayer()
{
	NodeName = "HelloToPlayer";
}

EBTNodeResult::Type UBTTask_HelloToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AMyCharacter* player = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AEnemy* Enemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetCharacter());
	if (Enemy == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AnimMontage = Enemy->Hello;
	UTextBlock* TextBlock = Cast<UTextBlock>(player->HUDWidget->GetWidgetFromName(TEXT("AIText")));
	TextBlock->SetText(FText::FromString(TEXT("안녕 어서와")));
	
	Enemy->PlayAnimMontage(AnimMontage);

	return EBTNodeResult::Succeeded;
}

