// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitlocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction %s"), *(HitLocation.ToString()));

		// TODO tell to aim
	}
}

bool ATankPlayerController::GetSightRayHitlocation(FVector& OutHitlocation) const
{
	int32 ViewportsizeX, ViewportsizeY;
	GetViewportSize(ViewportsizeX, ViewportsizeY);
	auto ScreenLocation = FVector2D(ViewportsizeX * CrosshairXLocation, ViewportsizeY * CrosshairYLocation);

	OutHitlocation = FVector(1.0);
		return true;

}