/** @file MyBTTask_ClearBlackBoardValue.h

 * @brief This file is the header file to the MyBTTask_ClearBlackBoardValue.cpp file

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_ClearBlackBoardValue.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTERGAME_API UMyBTTask_ClearBlackBoardValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UMyBTTask_ClearBlackBoardValue();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
