// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveFloor.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AMoveFloor::AMoveFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AMoveFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector moveVector = GetActorLocation();
	if (moveVector.Y > maxMoveRange.Y) {
		num = -1;
	}
	else if (moveVector.Y < minMoveRange.Y) {
		num = 1;
	}
	moveVector += num * moveSpeed * DeltaTime;
	
	SetActorLocation(moveVector);
}
