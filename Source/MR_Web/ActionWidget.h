// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionWidget.generated.h"

/**
 * 
 */
UCLASS()
class MR_WEB_API UActionWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/* What is going the player to shout? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
		FString shoutedAction;

	/*How long does this animation last?*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
		float duration;

	/*How long does this animation last?*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
		float currentLifeTime;

	/*Cool down of the shout.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
		float cooldown;

	/*Can the fighter use this?*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Action")
		bool bIsUnlocked;


};
