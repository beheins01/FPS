/** @file MyBTService_PlayerLocationIfSeen.cpp

 *  @brief This file is where I set up the AI's searching mechanic when it sees the player

 *

 *  Within this file I set up the service that tracks the player when it is seen
 *  I also set up the ability for the pawn to search for the player if they break line of sight with the AI

 *

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#include "MyBTService_PlayerLocationIfSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"



UMyBTService_PlayerLocationIfSeen::UMyBTService_PlayerLocationIfSeen()
{
	//This create a node in the behavior tree of the AI
	NodeName = "Update Player Location If Seen";
}

/** @brief Controles the AI movement, linetracing to look at the player

 *

 *  This function controls the AI to go to to the players location
 *	If the player breaks line of sight with the AI it will then search the area that the player 
 *  was last seen in
 *  If the AI doesnt find the character they will go back to their spawn point

 *

 *  @param OwnerComp This is a Behavior tree component that takes the value and stores it in the behavior tree
 *  @param NodeMemory This is an unreal integer that takes the node number and stores it in temporary memory
 *  @param Delta Seconds is an integer variable that contains the change in time
 * 
 *  @return null

 */
void  UMyBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


	/*These if and else statements allow for the AI to see the players character
	These also has the AI go to the player location
	If the Player cuts line of sight with the AI the AI will then begin to search for the player
	THis is done by going to the last known player location of the player */
	if (PlayerPawn == nullptr)
	{
		return;
	}

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
	}

	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
	
}