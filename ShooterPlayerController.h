/** @file ShooterPlayerController.h

 *  @brief This file is the header file to the ShooterPlayerController.cpp file
 
 *
 
 *  This file sets up the values for the restart timer
 *  This file also sets up the ability to implement the HUD
 
 *  @Author: Ben Heins

 *  @bug: No known bugs

 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTERGAME_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void GameHasEnded(class AActor *EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//These are the unreal engine properties for the character Heads Up Display (HUD)
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;


	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;

	//This is the unreal property that sets a delay until the game restarts 
	//This allows you to read the end game display
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5;

	FTimerHandle RestartTimer; //The FTimerHandle allows for the timer to be manipulated

	//This is what I can call to access the hud of the character
	UPROPERTY(EditAnywhere)
	UUserWidget* HUD;
	
};
