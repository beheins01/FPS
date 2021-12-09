/** @file MyBTService_PlayerLocationIfSeen.cpp

 * @brief This file is the header file to the MyBTService_PlayerLocationIfSeen.cpp file

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "MyBTService_PlayerLocationIfSeen.generated.h"


UCLASS()
class SIMPLESHOOTERGAME_API UMyBTService_PlayerLocationIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	//Allows me to see the if statements in the .cpp file that allows the AI to track the player location
	UMyBTService_PlayerLocationIfSeen();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)override;

	
};
