// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMainCube.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AMyMainCube::AMyMainCube()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	
	bDead = false;
	Energy = 100.0f;
	IsOverlappingItem = false;
}

// Called when the game starts or when spawned
void AMyMainCube::BeginPlay()
{
	Super::BeginPlay();
	
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyMainCube::OnBeginOverlap);

	/*if (MyCubeEnergyClass != nullptr)
	{
		MyCubeEnergyWidget = CreateWidget(GetWorld(), MyCubeEnergyClass);
		MyCubeEnergyWidget->AddToViewport();
	}*/
}

// Called every frame
void AMyMainCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Energy -= DeltaTime * EnergyThreshold;

	if (Energy <= 0.0f) {

		if (!bDead)
		{
			bDead = true;

			//GetMesh()->SetSimulatePhysics(true);

			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &AMyMainCube::RestartGame, 3.0f, false);
		}
	}
}


// Called to bind functionality to input
void AMyMainCube::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyMainCube::OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(TEXT("Recharge")))
	{

		Energy += 10.0f;

		if (Energy > 100.0f)
		{
			Energy = 100.0f;
		}

		OtherActor->Destroy();
	}
}

void AMyMainCube::RestartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("RestartGAme Function Worked!!"));
	//UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}



