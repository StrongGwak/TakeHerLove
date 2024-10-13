// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyAnimInstance.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Camera/CameraComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"

#include "Particles/ParticleSystem.h"
#include "Misc/OutputDeviceNull.h"
#include "ActionButton.h"
#include "ActionWidget.h"
#include "ActionStruct.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Engine/GameEngine.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeletalMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/rp_manuel_rigged_001_ue4.rp_manuel_rigged_001_ue4'"));
	if (SkeletalMesh.Succeeded()) 
	{
		GetMesh()->SetSkeletalMesh(SkeletalMesh.Object);
		GetMesh()->SetWorldLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
	}

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputContext(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_PlayerInput.IMC_PlayerInput'"));
	if (InputContext.Object != nullptr) 
	{
		DefaultContext = InputContext.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputMove(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Move.IA_Move'"));
	if (InputMove.Object != nullptr) 
	{
		MoveAction = InputMove.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputLook(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Look.IA_Look'"));
	if (InputLook.Object != nullptr) 
	{
		LookAction = InputLook.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputJump(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Jump.IA_Jump'"));
	if (InputJump.Object != nullptr) 
	{
		JumpAction = InputJump.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> InputRun(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Run.IA_Run'"));
	if (InputRun.Object != nullptr) 
	{
		RunAction = InputRun.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputInteract(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Interaction.IA_Interaction'"));
	if (InputInteract.Object != nullptr) 
	{
		InteractAction = InputInteract.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputCancel(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IA_Cancel.IA_Cancel'"));
	if (InputCancel.Object != nullptr)
	{
		CancelAction = InputCancel.Object;
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstance(TEXT("/Game/BluePrint/C++BP/ABP_MyCharacter.ABP_MyCharacter_C"));
	if (AnimInstance.Class != nullptr) 
	{
		GetMesh()->SetAnimInstanceClass(AnimInstance.Class);
	}

	static ConstructorHelpers::FObjectFinder<USoundBase>JumpSoundObj(TEXT("/Script/Engine.SoundWave'/Game/Sound/Hop.Hop'"));
	if (JumpSoundObj.Succeeded()) 
	{
		jumpSound = JumpSoundObj.Object;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget>HUD(TEXT("WidgetBlueprint'/Game/UMG/WB_CrossHarir.WB_CrossHarir_C'"));
	if (HUD.Succeeded()) 
	{
		HUDClass = HUD.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget>TempActionWidget(TEXT("WidgetBlueprint'/Game/UMG/WB_Action.WB_Action_C'"));
	if (TempActionWidget.Succeeded()) 
	{
		ActionWidgetClass = TempActionWidget.Class;
	}

	SpringArmPos = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpringArmPos"));
	SpringArmPos->SetupAttachment(RootComponent);
	SpringArmPos->SetRelativeLocation(FVector(0, 0, 55));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(SpringArmPos);
	SpringArm->TargetArmLength = 200;
	SpringArm->SocketOffset = FVector(0, 40, 0);
	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	CharacterMovement->MaxWalkSpeed = 300;

	


}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* playerController = Cast<APlayerController>(GetController())) 
	{
		if (UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer())) 
		{
			subSystem->AddMappingContext(DefaultContext, 0);
		}
	}
	
	HUDWidget = CreateWidget(GetWorld()->GetFirstPlayerController(), HUDClass);
	HUDWidget->AddToViewport();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult Hit;
	FVector StartTrace = Camera->GetComponentLocation();
	FVector EndTrace = StartTrace + (Camera->GetForwardVector() * 1000);
	//DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Red, false, 5.0f);

	bool isHit = GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_GameTraceChannel2);
	if (isHit) 
	{
		UPrimitiveComponent* NewHitComponent = Hit.GetComponent();
		HitActor = Hit.GetActor();
		if (OldHitComponent != NewHitComponent) 
		{
			if (NewHitComponent->ComponentHasTag("InteractObject"))
			{
				NewHitComponent->SetRenderCustomDepth(true);
			}
			if (OldHitComponent != nullptr) {
				OldHitComponent->SetRenderCustomDepth(false);
			}
			OldHitComponent = NewHitComponent;
		}
	}

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!bIgnoreInput) 
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMyCharacter::Jump);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &AMyCharacter::RunStart);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &AMyCharacter::RunEnd);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AMyCharacter::Interaction);
	}
	
	EnhancedInputComponent->BindAction(CancelAction, ETriggerEvent::Started, this, &AMyCharacter::Cancel);
	if (!bOnWidget) 
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
	}

}

void AMyCharacter::Move(const FInputActionValue& value)
{
	const FVector2D movementVector = value.Get<FVector2D>();
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, movementVector.Y);
	AddMovementInput(RightDirection, movementVector.X);
}

void AMyCharacter::Look(const FInputActionValue& value)
{
	const FVector2D LookAxisVector = value.Get<FVector2D>();
	if (!bIgnoreInput)
	{
		AddControllerYawInput(LookAxisVector.X * GetWorld()->DeltaTimeSeconds * mouseSpeed);
		AddControllerPitchInput(LookAxisVector.Y * GetWorld()->DeltaTimeSeconds * -mouseSpeed);
	}
	else 
	{
		SpringArmPosRotator = SpringArmPos->GetComponentRotation();
		SpringArmPosRotator.Pitch += LookAxisVector.Y * GetWorld()->DeltaTimeSeconds * mouseSpeed;
		SpringArmPosRotator.Yaw += LookAxisVector.X * GetWorld()->DeltaTimeSeconds * mouseSpeed;
		SpringArmPos->SetWorldRotation(SpringArmPosRotator);
	}
}

void AMyCharacter::RunStart()
{
	CharacterMovement->MaxWalkSpeed = 600;
}

void AMyCharacter::RunEnd()
{
	CharacterMovement->MaxWalkSpeed = 300;
}

void AMyCharacter::Interaction()
{
	bIgnoreInput = true;
	bOnWidget = true;
	CharacterMovement->StopActiveMovement();

	if (OldHitComponent->ComponentHasTag("InteractObject"))
	{
		FOutputDeviceNull ar;
		HitActor->CallFunctionByNameWithArguments(TEXT("Interact"), ar, nullptr, true);
	}

	if (OldHitComponent->ComponentHasTag("Enemy"))
	{
		CallAI(true);
	}

	ActionWidget = CreateWidget(GetWorld()->GetFirstPlayerController(), ActionWidgetClass);
	UActionWidget* ActionWidgetCpp = Cast<UActionWidget>(ActionWidget);
	TArray<UActionButton*> b = ActionWidgetCpp->Buttons;
	for (int i = 0; i < b.Num(); i++) 
	{
		UActionButton* button = b[i];
		button->Func_Action.BindUFunction(this, "CallActionButtonClick");
	}
	ActionWidgetOn();
}

void AMyCharacter::Cancel()
{
	if (ActionWidget != nullptr) 
	{
		bOnWidget = false;
		bIgnoreInput = false;
		ActionWidgetOff();
		if (OldHitComponent->ComponentHasTag("Enemy"))
		{
			CallAI(false);
		}
	}
	
}

void AMyCharacter::CallActionButtonClick(FActionStruct ActionStruct)
{
	bIgnoreInput = true;
	bOnWidget = false;
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritRoll = false;
	float Rate = PlayAnimMontage(ActionStruct.ActionAnim);
	ActionWidgetOff();

	FTimerHandle Handle;
	FTimerDelegate Callback = FTimerDelegate::CreateLambda([this]() 
	{ 
		bIgnoreInput = false; 
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritRoll = true;
	});

	GetWorld()->GetTimerManager().SetTimer(Handle, Callback, Rate, false);

	if (OldHitComponent->ComponentHasTag("InteractObject"))
	{
		FOutputDeviceNull ar;
		if (!ActionStruct.FunctionName.IsEmpty()) 
		{
			FString FormattedFunctionName = FString::Printf(TEXT("%s"), *ActionStruct.FunctionName);
			HitActor->CallFunctionByNameWithArguments(*FormattedFunctionName, ar, nullptr, true);
		}
	}

	if (OldHitComponent->ComponentHasTag("Enemy"))
	{
		CallAI(false);
	}
}

void AMyCharacter::CallAI(bool state)
{
	AAIController* AIController = Cast<AAIController>(HitActor->GetInstigatorController());
	AIController->GetBlackboardComponent()->SetValueAsBool(TEXT("IsCall"), state);
}

void AMyCharacter::ActionWidgetOn()
{
	ActionWidget->AddToViewport();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameAndUI());
}

void AMyCharacter::ActionWidgetOff()
{
	ActionWidget->RemoveFromParent();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
}
