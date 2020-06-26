// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnList.h"

USpawnList::USpawnList()
{
}

USpawnList::~USpawnList()
{
}

void USpawnList::WaveSetup()
{
    ListOfEnemys.Add(Enemy_Standard);
    ListOfEnemys.Add(Enemy_Large);
    ListOfEnemys.Add(Enemy_Speed);
    ListOfEnemys.Add(Enemy_Speed);
    ListOfEnemys.Add(Enemy_Speed);
}

void USpawnList::SetEnemyReferences(TSubclassOf<AActor> aEnemyStandard, TSubclassOf<AActor> aEnemyLarge, TSubclassOf<AActor> aEnemySpeed)
{
    Enemy_Standard = aEnemyStandard;
    Enemy_Large = aEnemyLarge;
    Enemy_Speed = aEnemySpeed;
}
