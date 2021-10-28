// Fill out your copyright notice in the Description page of Project Settings.
//THIS IS A FILE THAT I MADE AND EDITED

#include "MyShooterCharacter.h"
#include "Gun.h"

// Sets default values
AMyShooterCharacter::AMyShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	Gun = GetWorld()->SpawnActor<AGun>(GunClass);

	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
	
}

bool AMyShooterCharacter::IsDead() const
{
	return Health <= 0;
}

// Called every frame
void AMyShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move_Forward"), this, &AMyShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move_Right"), this, &AMyShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Look_Up"), this, &AMyShooterCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Look_Right"), this, &AMyShooterCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("Look_Up_Rate"), this, &AMyShooterCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("Look_Right_Rate"), this, &AMyShooterCharacter::LookRightRate);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AMyShooterCharacter::Shoot);
}

float AMyShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);

	return DamageToApply;

}
void AMyShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AMyShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AMyShooterCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AMyShooterCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AMyShooterCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AMyShooterCharacter::Shoot()
{
	Gun->PullTrigger();
}


