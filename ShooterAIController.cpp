/** @file ShooterAIController.cpp

 *  @brief This file sets up the AI's that are in my game

 *

 *  Within this file I set up the the ability to give my AI behavior and also set up two vectors "PlayerLocation, StartLocation."
 *  I also set up the ability for the code to see if the AI has died, so that they cannot shoot you when they are dead.

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyShooterCharacter.h"

 /** @brief This function controls what happens when the gamne begins for the AI

  *

  *  This function allows the AI to spawn in their designated locations while also initializing the ability
  *  to see player location and their start location

  */
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		// Puts vectors within the blackboard so that they can be called and used by both the code and the animations
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

	}
}

/** @brief This function sets up the tick

 *

 *  this function allows the ShooterAIController class to change every instance that
 *  the game is being run so that it changes every instant and adapts

 *

 *  @param DeltaSeconds is an integer variable that contains the change in time

 */
void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

/** @brief function that determines when the AI has died and the makes sure that they do not respawn

 *

 *  This function is checking to see if the AI has died and if it is dead the function ensures that the AI cannot respawn

 *

 *  @return True if the AI did die

 */
bool AShooterAIController::IsDead() const
{
	AMyShooterCharacter* ControlledCharacter = Cast<AMyShooterCharacter>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead();
	}

	return true;
}