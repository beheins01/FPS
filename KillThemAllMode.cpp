/** @file KillThemAllMode.cpp

 *  @brief This file creates and sets up the main mode that you will be trying to play when you spawn in

 *

 *  In this file I am creating the full gamemode where your goal is to kill all of the AI. 

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */

#include "KillThemAllMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"
//LO7
/** @brief This sets up the main gamemode that you spawn in, to just kill all the AI

 *

 *  This function goes through each AI and determines if they are dead or alive
 *	This function also helps to end the game if all the AI are dead and or keeps the 
 *  game going if there are any AI alive

 *

 *  @param PawnKilled This is bool that determines if the pawn is dead

 *  @return True which tells the game to end

 */
void AKillThemAllMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	//The following loops determine if the game should end or if the game is not over yet
	if (PlayerController != nullptr)
	{
		EndGame(false);
	}

	for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->IsDead())
		{
			return;
		}
	}

	EndGame(true);
}

/** @brief his is the funtion that executes the end of the game

 *

 *  This function determines if the game should end and if it should t starts the timer to reset the world

 *

 *  @param bIsPlayerWinner boolean that determines if the game is over

 */
void AKillThemAllMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))  //For Loop that goes to every controller in the world
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}