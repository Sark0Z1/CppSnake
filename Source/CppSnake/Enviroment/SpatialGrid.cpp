// CppSnake. Copyright SarkOZ1. All Right Reserved.


#include "CppSnake/Enviroment/SpatialGrid.h"
#include "CppSnake/Core/Grid.h"
#include "DrawDebugHelpers.h"
#include "Components/LineBatchComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogSpatialGrid, All, All);

ASpatialGrid::ASpatialGrid()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASpatialGrid::BeginPlay()
{
	Super::BeginPlay();
}

void ASpatialGrid::SetModel(const TSharedPtr<Snake::Grid>& Grid, int32 InCellSize)
{
	if (!Grid.IsValid())
	{
		UE_LOG(LogSpatialGrid, Fatal, TEXT("Grid is null!"));
	}
	GridDim = Grid.Get()->dim();
	CellSize = InCellSize;
	WorldWidth = GridDim.width * CellSize;
	WorldHeight = GridDim.heith * CellSize;
}

void ASpatialGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawGrid();
}

void ASpatialGrid::DrawGrid()
{
	if (!GetWorld() || !GetWorld()->LineBatcher) return;

	for (int32 i = 0; i < GridDim.heith + 1; ++i)
	{
		const FVector StartLocation = GetActorLocation() + GetActorForwardVector() * CellSize * i;
		// DrawDebugLine(GetWorld(), StartLocation, StartLocation + GetActorRightVector() * WorldWidth, FColor::Red, false, -1.0f, 0, 1.5f);
		GetWorld()->LineBatcher->DrawLine(StartLocation, StartLocation + GetActorRightVector() * WorldWidth,
		                                  FLinearColor::Red, 0, 1.5f);
	}

	for (int32 i = 0; i < GridDim.width + 1; ++i)
	{
		const FVector StartLocation = GetActorLocation() + GetActorRightVector() * CellSize * i;
		// DrawDebugLine(GetWorld(), StartLocation, StartLocation + GetActorForwardVector() * WorldHeight, FColor::Red, false, -1.0f, 0, 1.5f);
		GetWorld()->LineBatcher->DrawLine(StartLocation, StartLocation + GetActorForwardVector() * WorldHeight,
		                                  FLinearColor::Red, 0, 1.5f);
	}
}
