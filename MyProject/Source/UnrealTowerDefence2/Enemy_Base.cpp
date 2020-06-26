// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Base.h"

// Sets default values
AEnemy_Base::AEnemy_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyStaticMesh"));
	
	MaxHealth = 45;
	CurrentHealth = MaxHealth;
	
	WaypointsAreSet = false;
	
	EnemySpeed = 45.0f;
}

// Called when the game starts or when spawned
void AEnemy_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy_Base::MoveToWaypoint(float aDeltaTime)
{
	if(Waypoints.IsValidIndex(0) == false)
	{
		return;
	}



	if(WaypointsAreSet == false)
	{
		return;
	}
	
	if(FVector::Dist(GetActorLocation(), GoToWaypoint) < 20.5f )
	{
		GoToNextWaypoint();
	}

	FVector CurrentPosition = GetActorLocation();

	float deltaX = GoToWaypoint.X - CurrentPosition.X;
	float deltaY = GoToWaypoint.Y - CurrentPosition.Y;

	AngleToWaypoint = atan2(deltaX,deltaY);
	
	CurrentPosition.X += sin(AngleToWaypoint) * EnemySpeed * aDeltaTime;
	CurrentPosition.Y += cos(AngleToWaypoint) * EnemySpeed * aDeltaTime;
	
	
	SetActorLocation(CurrentPosition);
}

void AEnemy_Base::GoToNextWaypoint()
{
	if(Waypoints.Num() == 0)
	{
		EnemyGotToGoal();
		return;
	}
	
	GoToWaypoint = Waypoints[0];
	Waypoints.RemoveAt(0);
}

void AEnemy_Base::SetWaypoints(TArray<FVector> aWaypointList)
{
	Waypoints = aWaypointList;
	FVector CurrentPosition = GetActorLocation();

	
	GoToWaypoint = Waypoints[0];
	
	Waypoints.RemoveAt(0);

	



	WaypointsAreSet = true;
}

void AEnemy_Base::EnemyGotToGoal()
{
	PrimaryActorTick.bCanEverTick = false;
	//Death();
}



// Called every frame
void AEnemy_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy_Base::SetTurretReferences(ATurret* aAddToList)
{
	TowersAttackingEnemys.Add(aAddToList);
}


void AEnemy_Base::Death()
{
	for(int i = 0 ; i < TowersAttackingEnemys.Num(); i++)
	{
		//TowersAttackingEnemys[i]->EnemyWasKilled(GetName());		
	}
	
	Destroy(true);
}

void AEnemy_Base::TakeDamage(int aDamageTaken)
{
	CurrentHealth -= aDamageTaken;
	
	if(CurrentHealth <= 0)
	{
		Death();
	}
}

