// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FightingGameMode.generated.h"


/**
 * 
 */

class AFighter;
class AActor;

UCLASS()
class MR_WEB_API AFightingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	/* How far away should the actors be spawned? */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighting/Spawning")
	float spawnDistance;

	/*Spawn location of the player.*/
	UPROPERTY(BlueprintReadWrite, Category = "Fighting/Spawning")
	AActor* spawnPoint;

protected:
	/*Fighter controlled by the player.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Game Mode")
	TSubclassOf<AFighter> playerFighterClass;
	
	/*Fighter controlled by the AI.*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fighting/Game Mode")
	TSubclassOf<AFighter> aiFighterClass;

public:
	/*Fighter instance of the player*/
	UPROPERTY(BlueprintReadOnly, Category = "Fighting/Fighter")
	AFighter* playerFighter;

	/*Fighter instance of the player*/
	UPROPERTY(BlueprintReadOnly, Category = "Fighting/Fighter")
	AFighter* aiFighter;

	virtual void BeginPlay() override;

private: 
	void SetSpawnPoint();

	void SpawnFighters();

	void SpawnPlayerFighter();

	void SpawnAIFighter();
};
