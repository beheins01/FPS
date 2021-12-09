/** @file MyBTService_PlayerLocation.cpp

 *  @brief In This file I set up a component of the behavior tree

 *

 * In this file I set up the ability for the AI's behavior tree to see the location of 
 * the player and then trace it and follow that players locaation

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#include "MyBTService_PlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

UMyBTService_PlayerLocation::UMyBTService_PlayerLocation()
{
	NodeName = "Update Player Location";
}

/** @brief This function uses the blackboard within unreal

 *

 *  This function make a node for the tick functions in the blackboard whilch takes the player pawn
 *  and gets it in game location while also tracks the component.

 *

 *  @param OwnerComp This is a Behavior tree component that takes the value and stores it in the behavior tree
 *  @param NodeMemory This is an unreal integer that takes the node number and stores it in temporary memory
 *  @param Delta Seconds is an integer variable that contains the change in time

 *  @return null

 */
void  UMyBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn == nullptr)
	{
		return;
	}
	//This captures the balckboard components and allows it to be utilized to keep track of the player location
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
}