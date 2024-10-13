// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearTextBlock.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

UBTTask_ClearTextBlock::UBTTask_ClearTextBlock()
{
	NodeName = "ClearTextBlock";
}

EBTNodeResult::Type UBTTask_ClearTextBlock::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AMyCharacter* Player = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player == nullptr) 
	{
		return EBTNodeResult::Failed;
	}

	UTextBlock* TextBlock = Cast<UTextBlock>(Player->HUDWidget->GetWidgetFromName(TEXT("AIText")));
	TextBlock->SetText(FText::FromString(TEXT("")));

	return EBTNodeResult::Succeeded;
}
