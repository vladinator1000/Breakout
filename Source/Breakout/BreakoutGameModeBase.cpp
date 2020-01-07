// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BreakoutGameModeBase.h"
#include "BreakoutController.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Block.h"
#include "DrawDebugHelpers.h"

ABreakoutGameModeBase::ABreakoutGameModeBase()
{
  PlayerControllerClass = ABreakoutController::StaticClass();
}

void ABreakoutGameModeBase::BeginPlay()
{
  Super::BeginPlay();
  UWorld *World = GetWorld();
  Controller = Cast<ABreakoutController>(World->GetFirstPlayerController());
  SpawnBlocks();
}

void ABreakoutGameModeBase::SpawnBlocks()
{
  UWorld *World = GetWorld();
  UDA_Block *RandomBlock = BlockDataAssets[FMath::RandRange(0, BlockDataAssets.Num() - 1)];
  TSubclassOf<AActor> ActorClass = RandomBlock->BlockActorClass;

  for (int Row = 0; Row < Rows; Row++)
  {
    for (int Column = 0; Column < Columns; Column++)
    {
      float LocationX = SpawnOrigin.X + -1.0f * Row * BlockPadding.X;
      float LocationY = SpawnOrigin.Y + Column * BlockPadding.Y;

      FVector SpawnLocation = FVector(LocationX, LocationY, SpawnZHeight);

      World->SpawnActor<AActor>(ActorClass, SpawnLocation, FRotator::ZeroRotator);
    }
  }
}

void ABreakoutGameModeBase::HandleStartingNewPlayer_Implementation(APlayerController *NewPlayer)
{
  Super::HandleStartingNewPlayer_Implementation(NewPlayer);

  UWorld *World = GetWorld();
  Controller = Cast<ABreakoutController>(NewPlayer);
  SpawnBlocks();
}