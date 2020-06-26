// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Enemy_Base.h"
#include "Projectile.h"
#include "Turret.generated.h"

UCLASS()
class UNREALTOWERDEFENCE2_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

	UPROPERTY(EditAnywhere)
    USphereComponent* SphereTrigger;

	UPROPERTY(EditAnywhere)
      TArray<AActor*> EnemyInRange;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileRef;

	UPROPERTY(EditAnywhere)
	float ProjectileSpawnOffset;

	UPROPERTY(EditAnywhere)
	AEnemy_Base* EnemyToAttack;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ShootAtEnemy();
	
	UFUNCTION()
	void EnemyWasKilled(FString aName);
	
	UFUNCTION()
     virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
           int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
	
	
};
