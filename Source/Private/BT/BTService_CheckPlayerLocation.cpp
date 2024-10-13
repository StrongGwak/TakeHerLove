// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CheckPlayerLocation.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "MyAIController.h"
#include "Enemy.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

UBTService_CheckPlayerLocation::UBTService_CheckPlayerLocation()
{
	NodeName = "CheckPlayerLocation";
	Interval = 0.5f;
}

void UBTService_CheckPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	FVector AILocation = OwnerComp.GetAIOwner()->GetCharacter()->GetActorLocation();
	FVector PlayerLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(TEXT("PlayerLocation"));
	float Distance = FVector::Dist(PlayerLocation, AILocation);
	AMyCharacter* Player = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UTextBlock* TextBlock = Cast<UTextBlock>(Player->HUDWidget->GetWidgetFromName(TEXT("AIText")));
	
	if (Distance > 500.0f)
	{
		if (!isMoreFar)
		{
			TextBlock->SetText(FText::FromString(TEXT("어디가?")));
		}
		if (!isFar)
		{
			BlackboardComp->SetValueAsBool(TEXT("IsFar"), true);
		}
		isFar = true;
		isMoreFar = true;
		
		
	}
	else if (Distance > 300.0f) 
	{
		if (!isFar)
		{
			TextBlock->SetText(FText::FromString(TEXT("무슨 일 있어?")));
			BlackboardComp->SetValueAsBool(TEXT("IsFar"), true);
		}
		isFar = true;
	}
	else if (Distance <= 300.0f)
	{
		isFar = false;
		BlackboardComp->SetValueAsBool(TEXT("IsFar"), false);
	}

	if (isFar) 
	{
		currentTime += DeltaSeconds;
	}
	else 
	{
		currentTime = 0;
	}

	if (currentTime > 5.0f) 
	{
		AEnemy* Enemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetCharacter());
		Enemy->LikePercent -= 5;
		UE_LOG(LogTemp, Log, TEXT("%f"), Enemy->LikePercent);
		currentTime = 0;
	}

}
