// CppSnake. Copyright SarkOZ1. All Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CppSnake/Core/Types.h"
#include "GameFramework/Actor.h"
#include "SpatialGrid.generated.h"

namespace Snake
{
	class Grid;
}

UCLASS()
class CPPSNAKE_API ASpatialGrid : public AActor
{
	GENERATED_BODY()

public:
	ASpatialGrid();

	virtual void Tick(float DeltaTime) override;

	void SetModel(const TSharedPtr<Snake::Grid>& Grid, int32 InCellSize);

protected:
	virtual void BeginPlay() override;

private:
	Snake::Dimension GridDim;
	int32 CellSize;
	int32 WorldWidth;
	int32 WorldHeight;

	void DrawGrid();
};
