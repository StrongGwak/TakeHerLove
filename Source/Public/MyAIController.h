// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API AMyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	AMyAIController();

	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* EnemyBehaviorTree = nullptr;

	UPROPERTY()
	TSubclassOf<AActor> Target;

	UPROPERTY()
	TSubclassOf<AActor> FrontDoor;

	UPROPERTY()
	TSubclassOf<AActor> SlideDoor;

	UPROPERTY()
	TSubclassOf<AActor> BalconyDoor;

};
