// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Spawner.h"
#include "CoreMinimal.h"
#include "SpawnList.generated.h"
/**
 * 
 */
 
 UCLASS()
class UNREALTOWERDEFENCE2_API USpawnList : public UObject
{
	GENERATED_BODY()
	
public:
	USpawnList();
	~USpawnList();
	
	void WaveSetup();

	void SetEnemyReferences(TSubclassOf<AActor> aEnemyStandard, TSubclassOf<AActor> aEnemyLarge, TSubclassOf<AActor> aEnemySpeed);

	
	TArray<TSubclassOf<AActor>> ListOfEnemys;


	
    TSubclassOf<AActor> Enemy_Standard;
	TSubclassOf<AActor> Enemy_Large;
	TSubclassOf<AActor> Enemy_Speed;
	
};

