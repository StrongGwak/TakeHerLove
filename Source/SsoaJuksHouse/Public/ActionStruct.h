// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ActionStruct.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FActionStruct :public FTableRowBase
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ActionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* ActionAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsShow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FunctionName;
};