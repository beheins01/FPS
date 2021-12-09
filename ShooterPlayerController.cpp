/** @file ShooterPlayerController.cpp

 *  @brief This is the main file of the code that sets up screen for the player

 *

 * This file spawns the HUD that the player used while playing
 * This implements the Health bar into the HUD
 * This allows the game to show the win and lose screens when the game is over

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
//LO3


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

/** @brief This function controls what happens when the gamne begins for the ShooterCharacters HUD

  *

  *  This function attached the HUD to the players view port so that they can see their health and end game screens

  */
void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Allow the HUD to be called into the game
	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
	{
		//Adds the HUD to the players viewport
		HUD->AddToViewport();
	}
}

/** This function is where the win and lose screan are made and inherited from

 *

 *  This function allows for the end game win and loss screans to be implemented and used

 *

 *  @param EndGameFocus Determines how the game ended
 *  @param bIsWinner boolean that determines if the game is over and what screen to show

 */
void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();
	//This is the if-else statement that allows for the win and lose screen to be displayed
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}
	//This is what calls the delay in the timer when the game ends
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}


