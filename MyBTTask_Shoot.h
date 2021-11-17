
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTask_Shoot.generated.h"

/**
 * 
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
