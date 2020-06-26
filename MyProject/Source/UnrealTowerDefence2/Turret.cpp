// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"


// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));


	//SphereTrigger->SetRelativeLocation(this->GetActorLocation());
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

	//SphereTrigger = GetComponents<USphereComponent>(SphereTrigger);
	SphereTrigger->OnComponentBeginOverlap.AddDynamic(this, &ATurret::OnBeginOverlap);
	SphereTrigger->OnComponentEndOverlap.AddDynamic(this, &ATurret::OnEndOverlap);
	
	FTimerHandle handle;
    GetWorld()->GetTimerManager().SetTimer(handle,this,&ATurret::ShootAtEnemy,1.0f,true);
	ProjectileSpawnOffset = 111;
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurret::ShootAtEnemy()
{
	if(EnemyInRange.Num() <= 0)
	{
		return;
	}

	//if(EnemyToAttack == nullptr)
	//{
	//	return;
	//}
	
	FVector SpawnPosition = GetActorLocation();
	FRotator m_Rotator = GetActorRotation();
	
	SpawnPosition.Z += ProjectileSpawnOffset;

	AProjectile* ProjectileTemp;
        
	ProjectileTemp =  
	Cast<AProjectile>(GetWorld()->SpawnActor<AActor>(ProjectileRef, SpawnPosition, m_Rotator));
	
	//ProjectileTemp->Activate(EnemyToAttack);

}

//void ATurret::EnemyWasKilled(FString aName)
//{
//	for (int i = 0 ; i < EnemyInRange.Num() ; i++)
//	{
//		if(EnemyInRange[i]->GetName() == aName)
//		{
//			EnemyInRange.RemoveAt(i);
//		}
//	}
//
//	EnemyToAttack = Cast<AEnemy>(EnemyInRange[0]);
//}

void ATurret::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		AEnemy_Base* Enemy = Cast<AEnemy_Base>(OtherActor);
		if(Enemy == nullptr)
		{
			return;
		}
	
		EnemyInRange.Add(Enemy);
		if(EnemyInRange.Num() == 1)
		{
			//EnemyToAttack = Enemy;
		}
	}
}


void ATurret::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		for (int i = 0 ; i < EnemyInRange.Num() ; i++)
		{
			if(EnemyInRange[i]->GetName() == OtherActor->GetName())
			{
				EnemyInRange.RemoveAt(i);
			}
		}
	}
}
