/** @file SimpleShooterGameGameModeBase.h

 * @brief This file is the header file to the SimpleShooterGameGameModeBase.cpp file

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleShooterGameGameModeBase.generated.h"


UCLASS()
class SIMPLESHOOTERGAME_API ASimpleShooterGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled);
	
};
