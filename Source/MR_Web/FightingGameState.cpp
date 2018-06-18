// Fill out your copyright notice in the Description page of Project Settings.

#include "FightingGameState.h"
#include "ActionWidget.h"

UActionWidget* AFightingGameState::GetRandomAction()
{
	int32 randomIndex = FMath::FRandRange(0, actions.Num());
	return actions[randomIndex];
}

UActionWidget* AFightingGameState::GetActionOfType(FString shoutedAction)
{
	for (int32 i = 0; i < actions.Num(); i++)
	{
		if (actions[i]->shoutedAction == shoutedAction)
			return actions[i];
	}

	UE_LOG(LogTemp, Warning, TEXT("No action found in gamestate for %s"), *shoutedAction)

	return actions[0];
}
