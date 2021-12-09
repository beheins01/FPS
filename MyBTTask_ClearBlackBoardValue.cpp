/** @file MyBTTask_ClearBlackBoardValue.cpp

 *  @brief In This file I set up a task of the behavior tree

 *

 * In this file I set up the task for clearing of the blackboard value when the code is run

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#include "MyBTTask_ClearBlackBoardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_ClearBlackBoardValue::UMyBTTask_ClearBlackBoardValue()
{
	NodeName = TEXT("Clear Blackboard Value");
}

/** @brief This function just clears the blackboard

 *

 *  Clears the blackboard in Unreal

 *

 *  @param OwnerComp This is a Behavior tree component that takes the value and stores it in the behavior tree
 *  @param NodeMemory This is an unreal integer that takes the node number and stores it in temporary memory

 *  @return Succeeded which is a NodeResult within unreal engine

 */
EBTNodeResult::Type UMyBTTask_ClearBlackBoardValue::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}