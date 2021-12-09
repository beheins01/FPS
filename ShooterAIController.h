/** @file ShooterAIController.h

 *  @brief This file is the header file to the ShooterAIController.cpp file

 *

 *  In this file I set up the Class AShooterAIControiller so that I can call the functions in the .cpp file

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"


UCLASS()
//LO2a
//In an inheritance relationship, the class being inherited from is called the parent class, base class, or superclass, 
//and the class doing the inheriting is called the child class, derived class, or subclass.
// https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/
class SIMPLESHOOTERGAME_API AShooterAIController : public AAIController		//LO2
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaSeconds) override;			//Use override just for safety to make sure no bugs occur during gameplay
	
	//This checks to see if the AI has died
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior;

	
};
