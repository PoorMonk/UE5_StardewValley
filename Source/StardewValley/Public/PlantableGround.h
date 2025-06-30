// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantableGround.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class STARDEWVALLEY_API APlantableGround : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantableGround();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Planting")
	void PlantSeed();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UStaticMeshComponent* GroundMesh;
    
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UBoxComponent* InteractionBox;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planting")
	bool bIsPlanted = false;
};
