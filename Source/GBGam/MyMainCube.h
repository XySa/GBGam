// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyMainCube.generated.h"

UCLASS()
class GBGAM_API AMyMainCube : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyMainCube();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Energy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float EnergyThreshold = 1.5f;

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* HitComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	/*UPROPERTY(EditAnywhere, Category = "UI HUD")
		TSubclassOf<UUserWidget> MyCubeEnergyClass;*/
		//UUserWidget* MyCubeEnergyWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
		bool IsOverlappingItem;

	void RestartGame();

	bool bDead;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	
};
