// CppSnake. Copyright SarkOZ1. All Right Reserved.


#include "CppSnake/Framework/MainPawn.h"
#include "Camera/CameraComponent.h"


namespace
{
	float HalfFOVTan(float FOVDegrees)
	{
		return FMath::Tan(FMath::DegreesToRadians(FOVDegrees * 0.5f));
	}

	float VerticalFOV(float HorizontalFOVDegrees, float ViewportAspectHW)
	{
		return FMath::RadiansToDegrees(
			2.0f * FMath::Atan(FMath::Tan(FMath::DegreesToRadians(HorizontalFOVDegrees) * 0.5f) * ViewportAspectHW));
	}
}

AMainPawn::AMainPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	SetRootComponent(Origin);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(Origin);
}

void AMainPawn::UpdateLocation(const Snake::Dimension& InDim, int32 InCellSize, const FTransform& InGridOrigin)
{
	Dim = InDim;
	CellSize = InCellSize;
	GridOrigin = InGridOrigin;

	auto* Viewport = GEngine->GameViewport->Viewport; // return ViewportSize
	Viewport->ViewportResizedEvent.AddUObject(this, &AMainPawn::OnViewportResized);

#if WITH_EDITOR
	OnViewportResized(Viewport, 0);
#endif
}

void AMainPawn::OnViewportResized(FViewport* Viewport, uint32 Value)
{
	if (!Viewport || Viewport->GetSizeXY().Y == 0 || Dim.heith == 0) return;

	const float WorldWidth = Dim.width * CellSize;
	const float WorldHeight = Dim.heith * CellSize;
	
	float LocationZ = 0.0f;
	
	const float ViewportAspect = static_cast<float>(Viewport->GetSizeXY().X) / Viewport->GetSizeXY().Y;
	const float GridAspect = static_cast<float>(Dim.width / Dim.heith);

	if (ViewportAspect <= GridAspect)
	{
		LocationZ = WorldWidth / HalfFOVTan(Camera->FieldOfView);
	}
	else
	{
		const float VertFOV = VerticalFOV(Camera->FieldOfView, 1.0f / ViewportAspect);
		LocationZ = WorldHeight / HalfFOVTan(VertFOV);
	}

	const FVector NewPawnLocation = GridOrigin.GetLocation() +
		0.5f * FVector(WorldHeight, WorldWidth, LocationZ);

	SetActorLocation(NewPawnLocation);
}
