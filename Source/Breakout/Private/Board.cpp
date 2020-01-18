// Fill out your copyright notice in the Description page of Project Settings.

#include "Board.h"

// Sets default values
ABoard::ABoard()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMeshComponent);

	AttributeSet = CreateDefaultSubobject<UBreakoutAttributeSet>(TEXT("AttributeSet"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();

	if (DefaultBallAsset)
	{
		ABall *Ball = GetWorld()->SpawnActor<ABall>(
				DefaultBallAsset->BallActorClass,
				GetActorLocation() + FVector(BallSpawnDistance, 0, 0),
				FRotator::ZeroRotator);

		GrabBall(Ball);
	}
}

void ABoard::GrabBall(ABall *Ball)
{
	Balls.Emplace(Ball);
	Ball->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepWorld, true));
}

void ABoard::LaunchBalls()
{
	for (const auto Ball : Balls)
	{
		Ball->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

		const FVector Impulse = StaticMeshComponent->GetComponentVelocity() + FVector(BallLaunchSpeed, 0, 0);
		Ball->StaticMeshComponent->AddImpulse(Impulse);
	};

	Balls.Empty();
}

UAbilitySystemComponent *ABoard::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}