
#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGameGameModeBase.h"
#include "KillThemAllMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTERGAME_API AKillThemAllMode : public ASimpleShooterGameGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PawnKilled(APawn* PawnKilled)override;

private:
	void EndGame(bool bIsPlayerWinner);
};
