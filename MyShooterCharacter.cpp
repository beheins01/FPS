/** @file MyShooterCharacter.cpp

 *  @brief This is the main file of the code that sets up the players character in the game

 *

 * This file spawns the character whenever the game begins
 * This file also sets up the players health and gives a mount where you can place the gun mesh from the gun.cpp file
 * This also sets up the ability for the game to decrease the health bar when the player takes damage
 * This file also sets up the input functionality that will be used when the player is controlling the character
 * This file also sets up the death of the players character and in what situation that would happen
 * This file also allows the player to have control over the camera so that they can aim their gun

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */

#include "MyShooterCharacter.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "SimpleshooterGameGameModeBase.h"

// Sets default values
AMyShooterCharacter::AMyShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/** @brief This function controls what happens when the gamne begins for your character

  * 

  *  This function allows the player to spawn while also giving them their full healht
  *  This function also allows the gun to spawn in the players charater while also setting up
  *  The weapon socket so more types of weapons can be implemented

  */
void AMyShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Sets the players/AI's health to max health when the game is started or when the pawn is spawned
	Health = MaxHealth;		

	//This sets the gun to spawn on the character or AI when the game is loaded
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);			

	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
	
}


/** @brief This function is what tell the pawn to play the death animation when there health is 0

 */
bool AMyShooterCharacter::IsDead() const
{
	return Health <= 0;
}


/** @brief This function checks health percentages

 *

 *  This function is constantly checking the health percentage of the pawn
 *    Allows for the health bar th change when the player or AI is shot

 */
float AMyShooterCharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

/** @brief This function sets up the tick

 *

 *  this function allows the Shooter Character class to change every instance that
 *  the game is being run so that it changes every instant and adapts

 *

 *  @param DeltaSeconds is an integer variable that contains the change in time

 */
void AMyShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/** @brief This function sets up the movement inputs

 *

 *  Called to bind functionality to input
 *  in the game settings you are able to see what keys are bound to the following functionalities
 *  (Move_Forward, Move_Right, Look_Up, Look_Right, Look_Up_Rate, Look_Right_Rate, Jump, Shoot)

 *

 *  @param PlayerInputComponent Key bind variable that is enabled within unreal engine

 */
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


//LO1a
/** @brief This function allows the player to take damage

 *

 *  This is the function that applied the damage to the pawn and allows for the rest of the health functions to aquire
 *  the data needed to execute their functionality

 *

 *  @param DamageAmount This is a float value that determines how much health damage to apply
 *  @param DamageEvent This is the thing that causes the damage to the pawn
 *  @param EventInstigator This is what pawn caused the damage
 *  @param DamageCauser This is what gun caused the damage

 *  @return DamageToApply this is a integer value that is the amount of damage done

 */
float AMyShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);

	if (IsDead())
	{
		ASimpleShooterGameGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}

		DetachFromControllerPendingDestroy();		//When the controller dies the camera is removed and reset
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	}

	return DamageToApply;

}
//LO1a
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


