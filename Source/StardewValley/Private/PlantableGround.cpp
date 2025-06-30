// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantableGround.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APlantableGround::APlantableGround()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	GroundMesh = CreateDefaultSubobject<UStaticMeshComponent>("GroundMesh");
	GroundMesh->SetupAttachment(RootComponent);

	InteractionBox = CreateDefaultSubobject<UBoxComponent>("InteractionBox");
	InteractionBox->SetupAttachment(RootComponent);
	InteractionBox->SetBoxExtent(FVector(100.f, 100.f, 50.f));
}

// Called when the game starts or when spawned
void APlantableGround::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlantableGround::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlantableGround::PlantSeed()
{
	if (bIsPlanted)
	{
		UE_LOG(LogTemp, Warning, TEXT("Already planted!"));
		return;
	}
    
	bIsPlanted = true;
	UE_LOG(LogTemp, Warning, TEXT("Seed planted!"));
    
	// 先简单地改变颜色来表示种植了
	if (GroundMesh && GroundMesh->GetMaterial(0))
	{
		// 这里我们先用日志，稍后会改成实际的视觉效果
		UE_LOG(LogTemp, Log, TEXT("PlantSeed: Change Material"));
	}
}

