// Fill out your copyright notice in the Description page of Project Settings.
//THIS IS A FILE THAT I MADE AND EDITED

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTERGAME_API AMyShooterCharacter : public ACharacter		//Here in the program the class : AMyShooterCharacter is inheriting from ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintPure)		//This is almost like Blueprintconst instead BlueprintPure only affects the output it produces
									//It also removes the need for an execution pin in the amination blueprint in Unreal
	bool IsDead() const;

	UFUNCTION(BlueprintPure)		
	float GetHealthPercent() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void Shoot();

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	


	UPROPERTY(EditAnywhere)
	float RotationRate = 30;
	
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
	float Health;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;
};
