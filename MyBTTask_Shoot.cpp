/** @file MyBTTask_Shoot.cpp

 *  @brief In This file I set up a task of the behavior tree

 *

 * In this file I set up the task for the AI to shoot at the player in the game

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#include "MyBTTask_Shoot.h"
#include "AIController.h"
#include "MyShooterCharacter.h"


UMyBTTask_Shoot::UMyBTTask_Shoot()
{
	NodeName = "Shoot";
}

/** @brief This sets up the behavior tree in the game

 *

 *  This allows the shooting of the gun to stick with the character and gun

 *

 *  @param OwnerComp This is a Behavior tree component that takes the value and stores it in the behavior tree
 *  @param NodeMemory This is an unreal integer that takes the node number and stores it in temporary memory

 *  @return Failed or Succeeded

 */
EBTNodeResult::Type UMyBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AMyShooterCharacter* Character = Cast<AMyShooterCharacter> (OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Character->Shoot();

	return EBTNodeResult::Succeeded;
}