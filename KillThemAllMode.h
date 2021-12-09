/** @file KillThemAllMode.h

 * This file is the header file to the KillThemAllMode.cpp file

 *  @brief Author: Ben Heins

 *  @bug: No known bugs

 */
#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGameGameModeBase.h"
#include "KillThemAllMode.generated.h"

UCLASS()
class SIMPLESHOOTERGAME_API AKillThemAllMode : public ASimpleShooterGameGameModeBase
{
	GENERATED_BODY()
	
public:
	//This allows the code to detect when the pawn or character is dead
	virtual void PawnKilled(APawn* PawnKilled)override;

private:
	//This allows for the .cpp file to determine if the game is over
	void EndGame(bool bIsPlayerWinner);
};
