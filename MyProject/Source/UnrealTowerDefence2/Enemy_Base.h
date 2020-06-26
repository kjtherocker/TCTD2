// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy_Base.generated.h"

class ATurret;
UCLASS()
class UNREALTOWERDEFENCE2_API AEnemy_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy_Base();
	virtual void MoveToWaypoint(float aDeltaTime);

	virtual void GoToNextWaypoint();

	virtual void SetWaypoints(TArray<FVector> aWaypointList);

	virtual void EnemyGotToGoal();
	
protected:
            // Called when the game starts or when spawned
    virtual void BeginPlay() override;
	

	
	virtual void Tick(float DeltaTime) override;


	virtual void SetTurretReferences(ATurret* aAddToList);	
	virtual void Death();

	int MaxHealth;


public:	

	
     TArray<ATurret*> TowersAttackingEnemys;
	
    UPROPERTY(VisibleAnywhere)
    int CurrentHealth;

	TArray<FVector> Waypoints;

	UPROPERTY(EditAnywhere)
    FVector GoToWaypoint;

	UPROPERTY(VisibleAnywhere)
    FVector Testo;

	UPROPERTY(EditAnywhere)
    float EnemySpeed;
			
	UPROPERTY(VisibleAnywhere)
     UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(EditAnywhere)
    float AngleToWaypoint;

	UFUNCTION()
    virtual void TakeDamage(int aDamageTaken);
	
	bool WaypointsAreSet;

};
