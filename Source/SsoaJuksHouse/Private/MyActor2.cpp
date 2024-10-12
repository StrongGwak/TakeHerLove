// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*FVector currentLoctaion = GetActorLocation();
	FRotator currentRotation = GetActorRotation();

	currentLoctaion += (PlayerVelocity * DeltaTime);
	currentRotation += (DeltaTime * PlayerRotation);

	SetActorLocation(currentLoctaion);

	SetActorRotation(currentRotation);*/
	AddActorLocalRotation(PlayerRotation* DeltaTime);

}

void AMyActor2::Test(int num) const {
	FString name = "Unreal5 z";
	//for (int i = 0; i < num; i++) {
	//	UE_LOG(LogTemp, Display, TEXT("Hellow %s"), *name);
	//	UE_LOG(LogTemp, Warning, TEXT("Hellow %s"), *name);
	//	UE_LOG(LogTemp, Error, TEXT("Hellow %s"), *name);
	//}
	
}
