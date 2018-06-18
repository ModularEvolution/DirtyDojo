// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FightingGameState.generated.h"

/**
 * 
 */

class UActionWidget;

UCLASS()
class MR_WEB_API AFightingGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	/*All the possible actions*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Actions")
  	TArray<UActionWidget*> actions;

	UActionWidget* GetRandomAction();

	UActionWidget* GetActionOfType(FString shoutedAction);
	 
};
  