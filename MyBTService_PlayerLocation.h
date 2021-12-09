/** @file MyBTService_PlayerLocation.h

 *  @brief This file is the header file to the MyBTService_PlayerLocation.cpp file

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "MyBTService_PlayerLocation.generated.h"

/**
 * This sets up in the Behavior Tree within the unreal engine file to utilize the player location
 */
UCLASS()
class SIMPLESHOOTERGAME_API UMyBTService_PlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UMyBTService_PlayerLocation();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)override;
	
};
