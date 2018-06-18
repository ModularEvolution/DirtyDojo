// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBlueprint.h"
#include "Action.generated.h"

/**
 * 
 */
UCLASS()
class MR_WEB_API UAction : public UWidgetBlueprint
{
	GENERATED_BODY()
	
	/* What is going the player to shout? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
	FString shoutedAction;

	/*How long does this animation last?*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
	float duration;
	
	/*Cool down of the shout.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
	float cooldown;

	/*Can the fighter use this?*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
	bool bIsUnlocked;
	
};
