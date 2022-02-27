// Fill out your copyright notice in the Description page of Project Settings.


#include "FloationgEnergyActor.h"

// Sets default values
AFloationgEnergyActor::AFloationgEnergyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloationgEnergyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloationgEnergyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.X += DeltaHeight * ValueX;
	NewLocation.Y += DeltaHeight * ValueY;
	NewLocation.Z += DeltaHeight * ValueZ;

	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

