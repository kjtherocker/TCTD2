// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy_Base.h"
#include "Projectile.generated.h"

UCLASS()
class UNREALTOWERDEFENCE2_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//UPROPERTY(EditAnywhere)
	//AEnemy* EnemyToAttack; 

	UPROPERTY(EditAnywhere)
	int ProjectileDamage;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* m_Mesh;
	
	UPROPERTY(EditAnywhere)
	float ProjectileSpeed;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GoToEnemy(float aDeltatime);

	virtual void Activate(AEnemy_Base* aEnemy);
	virtual void Deactivate();


	bool ProjectileState;

	UFUNCTION()
       void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
       	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
