// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FightingGameState.h"
#include "Fighter.generated.h"

class UAction;
class AFightingGameState;

UCLASS()
class MR_WEB_API AFighter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFighter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// How much stress should be regened every second?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Stress")
	float stressRegen;

	// Stress level of the player.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Stress")
	float stressLevel;

	// Hitpoints of the character.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Fighter")
	float maxHitpoint;

	// Holds the river of actions.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighting/Fighter")
	TArray<UActionWidget*> actionRiver;

	//How many actions should he in the river at any time?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Actions")
	int32 actionCount = 4;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Adds the shouted action to the player.
	UFUNCTION(BlueprintCallable, Category = "Fighting/Actions")
		UActionWidget* ShoutAction(FString shoutedAction);

protected: 
	virtual void PerformCurrentAction();

private:
	AFightingGameState* gameState;

	float currentStressLevel;

	float nextAttackTime;

	float currentHitPoints;
};
