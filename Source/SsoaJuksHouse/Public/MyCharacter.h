// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MyCharacter.generated.h"

UCLASS()
class SSOAJUKSHOUSE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SpringArmPos = nullptr;

	UPROPERTY()
	FRotator SpringArmPosRotator;

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera = nullptr;

	UPROPERTY(EditAnywhere, Category = "Montage")
	UAnimMontage* InteractMontage = nullptr;

	class UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();

	UPROPERTY()
	bool bIgnoreInput = false;

	UPROPERTY()
	bool bOnWidget = false;

public:
	UPROPERTY(EditAnywhere)
	float mouseSpeed = 30;

private:
	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputMappingContext* DefaultContext;
	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputAction* MoveAction;
	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputAction* LookAction;
	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputAction* JumpAction;
	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputAction* RunAction;
	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputAction* InteractAction;
	UPROPERTY(VisibleAnywhere, Category = "Input")
	class UInputAction* CancelAction;

	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
	void RunStart();
	void RunEnd();
	void Interaction();
	void Cancel();

public:
	UPROPERTY(EditAnywhere)
	class USoundBase* jumpSound = nullptr;

public:
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> HUDClass = nullptr;

	UPROPERTY()
	UUserWidget* HUDWidget;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<class UUserWidget> ActionWidgetClass = nullptr;

	UPROPERTY()
	UUserWidget* ActionWidget = nullptr;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
	bool isAim = false;

private:
	UPROPERTY(VisibleAnywhere, Category = "Status")
	class UPrimitiveComponent* OldHitComponent = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Status")
	class AActor* HitActor = nullptr;

public:
	UFUNCTION()
	void CallActionButtonClick(FActionStruct ActionStruct);

	void CallAI(bool state);
	void ActionWidgetOn();
	void ActionWidgetOff();
};
