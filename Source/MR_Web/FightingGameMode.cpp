// Fill out your copyright notice in the Description page of Project Settings.

#include "FightingGameMode.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Fighter.h"

void AFightingGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetSpawnPoint();
	SpawnFighters();
}

void AFightingGameMode::SetSpawnPoint()
{
	// Find all target points in the world.
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), FoundActors);

	// Use the first one.
	if (FoundActors.Num() > 0)
	{
		spawnPoint = FoundActors.Pop();
	}

	// Log error if we didn't found any.
	else
	{
		UE_LOG(LogTemp, Error, TEXT("There is no target point for spawning. Please add one before playing."))
	}
}

void AFightingGameMode::SpawnFighters()
{
	SpawnPlayerFighter();
	//SpawnAIFighter();
}

void AFightingGameMode::SpawnPlayerFighter()
{
	// Calculate the spawn location and rotation of the player fighter.
	FVector SpawnLocation = spawnPoint->GetActorLocation();
	SpawnLocation.X -= spawnDistance;

	FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);

	playerFighter = GetWorld()->SpawnActor<AFighter>(playerFighterClass, SpawnLocation, SpawnRotation);
}

void AFightingGameMode::SpawnAIFighter()
{
	// Calculate the spawn location and rotation of the player fighter.
	FVector SpawnLocation = spawnPoint->GetActorLocation();
	SpawnLocation.X += spawnDistance;

	FRotator SpawnRotation = FRotator(0.f, 180.f, 0.f);


	aiFighter = GetWorld()->SpawnActor<AFighter>(aiFighterClass, SpawnLocation, SpawnRotation);
}
