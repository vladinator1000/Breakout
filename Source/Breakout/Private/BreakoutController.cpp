// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakoutController.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"
#include "BreakoutGameModeBase.h"
#include "DrawDebugHelpers.h"
#include "Board.h"

ABreakoutController::ABreakoutController()
{
  BoardToSpawn = ABoard::StaticClass();
}

void ABreakoutController::BeginPlay()
{
  Super::BeginPlay();
  UWorld *World = GetWorld();

  FVector BoardSpawnLocation, BoardSpawnDirection;
  DeprojectScreenPositionToWorld(0, 0, BoardSpawnLocation, BoardSpawnDirection);

  BoardSpawnLocation.Z = World->GetAuthGameMode<ABreakoutGameModeBase>()->SpawnZHeight;

  Board = World->SpawnActor<ABoard>(BoardToSpawn, BoardSpawnLocation, FRotator::ZeroRotator);
}

void ABreakoutController::SetupInputComponent()
{
  Super::SetupInputComponent();
  InputComponent->BindAxis("MoveRight", this, &ABreakoutController::MoveRight);
  InputComponent->BindAction("Fire", IE_Pressed, this, &ABreakoutController::Fire);
}

void ABreakoutController::MoveRight(const float Value)
{
  if (Value && Board)
  {
    FVector Offset = FVector::ZeroVector;
    Offset.Y = Value * GetWorld()->GetDeltaSeconds() * MovementSpeed * 1000.f;
    Board->StaticMeshComponent->AddForce(Offset, NAME_None, true);

    const FVector Velocity = Board->GetVelocity();
    const bool AreDirectionsDifferent = (Value > 0) != (Velocity.Y > 0);

    if (AreDirectionsDifferent)
    {
      // To make movement feel more responsive
      Board->StaticMeshComponent->SetPhysicsLinearVelocity(FVector::ZeroVector);
      Board->StaticMeshComponent->AddImpulse(Offset * DirectionChangedImpulseStrength);
    }
  }
}

void ABreakoutController::Fire()
{
  Board->LaunchBalls();
}
