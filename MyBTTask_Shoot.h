/** @file MyBTTask_Shoot.h

 *  @brief This file is the header file to the MyBTTask_Shoot.h.cpp file

 *  This file is what allows me to set up the shooting mechanic within my .cpp file and game 

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTask_Shoot.generated.h"

/**
 *	This file is what allows me to set up the shooting mechanic within my .cpp file and game 
 */
UCLASS()
class SIMPLESHOOTERGAME_API UMyBTTask_Shoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UMyBTTask_Shoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory) override;

};
