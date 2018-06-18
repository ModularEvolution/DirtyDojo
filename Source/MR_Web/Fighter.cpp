// Fill out your copyright notice in the Description page of Project Settings.

#include "Fighter.h"
#include "FightingGameState.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
AFighter::AFighter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFighter::BeginPlay()
{
	Super::BeginPlay();

	// Set reference to game state.
	gameState = GetWorld()->GetGameState<AFightingGameState>();

	// Get all the river elements from the game state.
	for (int32 i = 0; i < actionCount; i++)
	{
		auto action = gameState->GetRandomAction();
		actionRiver.Add(action);
	}

	currentStressLevel = 0.f;

	currentHitPoints = maxHitpoint;
}

// Called every frame
void AFighter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If it's time to attack, perform the attack.
	if (nextAttackTime < 0.f)
	{
		PerformCurrentAction();
	}
	// Update the waiting time.
	else
	{
		nextAttackTime -= DeltaTime;
	}

	// Relax the player if he is stressed now.
	if (stressLevel > 0.f)
	{
		stressLevel -= stressRegen * DeltaTime;
	}
	// default to 0 stress.
	else
	{
		stressLevel = 0.f;
	}
}

// Called to bind functionality to input
void AFighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

FActionData AFighter::ShoutAction(FString shoutedAction)
{
	return gameState->GetActionOfType(shoutedAction);
}

void AFighter::PerformCurrentAction()
{
	auto currentAction = actionRiver.Pop();
	nextAttackTime = currentAction.duration;

	UE_LOG(LogTemp, Warning, TEXT("%s performed %s"), *this->GetName(), *currentAction.shoutedAction);

	auto newAction = gameState->GetRandomAction();
	actionRiver.Add(newAction);
}

