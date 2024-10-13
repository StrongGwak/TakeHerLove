// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Talk.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BehaviorTree/BTNode.h"
#include "MyCharacter.h"
#include "Enemy.h"
#include "MyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

UBTTask_Talk::UBTTask_Talk()
{
	NodeName = "Talk";
}

EBTNodeResult::Type UBTTask_Talk::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AMyCharacter* Player = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UTextBlock* TextBlock = Cast<UTextBlock>(Player->HUDWidget->GetWidgetFromName(TEXT("AIText")));
	if (TextBlock == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AEnemy* Enemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetCharacter());
	if (Enemy == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UBTNode* TempParentNode = GetParentNode()->GetParentNode();
	FString ParentNodeName = TempParentNode->GetNodeName();

	if (ParentNodeName.Equals(TEXT("MoveToHole")))
	{
		TextBlock->SetText(FText::FromString(TEXT("우리 집 구경시켜줄게 따라와")));
		Enemy->PlayAnimMontage(Enemy->Talk);
	} 
	else if (ParentNodeName.Equals(TEXT("Cook")))
	{
		TextBlock->SetText(FText::FromString(TEXT("여기가 부엌이야")));
		Enemy->PlayAnimMontage(Enemy->Talk2);
	}
	else if (ParentNodeName.Equals(TEXT("StorageTalk")))
	{
		TextBlock->SetText(FText::FromString(TEXT("여기는 창고야")));
		Enemy->PlayAnimMontage(Enemy->Talk3);
	}
	else if (ParentNodeName.Equals(TEXT("CorridorTalk")))
	{
		TextBlock->SetText(FText::FromString(TEXT("이거는 우리 아버지 취미")));
		Enemy->PlayAnimMontage(Enemy->Talk2);
	}
	else if (ParentNodeName.Equals(TEXT("FatherRoomTalk")))
	{
		TextBlock->SetText(FText::FromString(TEXT("여기는 서재야")));
		Enemy->PlayAnimMontage(Enemy->Talk);
	}
	else if (ParentNodeName.Equals(TEXT("GrandMotherRoomTalk")))
	{
		TextBlock->SetText(FText::FromString(TEXT("여기는 우리 할머니 방이야")));
		Enemy->PlayAnimMontage(Enemy->Talk2);
	}
	else if (ParentNodeName.Equals(TEXT("GirlRoomTalk")))
	{
		TextBlock->SetText(FText::FromString(TEXT("여기는 내 방이야")));
		Enemy->PlayAnimMontage(Enemy->Talk3);
	}
	else if (ParentNodeName.Equals(TEXT("BalconyTalk")))
	{
		TextBlock->SetText(FText::FromString(TEXT("우리 근데 무슨 사이야?")));
		Enemy->PlayAnimMontage(Enemy->Talk3);
	}

	
		
	return EBTNodeResult::Succeeded;
}
