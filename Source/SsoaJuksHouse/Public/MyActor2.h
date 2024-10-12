// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class SSOAJUKSHOUSE_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void Test(int num) const;

public:
	UPROPERTY(EditAnywhere)
	float number = 3.14;
	UPROPERTY(VisibleAnywhere)
	int number2 = 1000;
	UPROPERTY(EditAnywhere)
	FVector MyVector = FVector(0.0, 0.0, 0.0);

public:
	UPROPERTY(EditAnywhere, Category = "Player Move")
	FVector PlayerVelocity = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Player Rotation")
	FRotator PlayerRotation = FRotator(0, 0, 0);

};
