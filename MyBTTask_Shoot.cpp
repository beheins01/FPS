// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_Shoot.h"
#include "AIController.h"
#include "MyShooterCharacter.h"


UMyBTTask_Shoot::UMyBTTask_Shoot()
{
	NodeName = "Shoot";
}

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