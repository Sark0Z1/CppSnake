// CppSnake. Copyright SarkOZ1. All Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CppSnake/Core/Types.h"
#include "GameFramework/Pawn.h"
#include "MainPawn.generated.h"

class UCameraComponent;

UCLASS()
class CPPSNAKE_API AMainPawn : public APawn
{
	GENERATED_BODY()

public:
	AMainPawn();

	void UpdateLocation(const Snake::Dimension& InDim, int32 InCellSize, const FTransform& InGridOrigin);

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Origin;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

private:
	Snake::Dimension Dim;
	int32 CellSize;
	FTransform GridOrigin;
	
	void OnViewportResized (FViewport* Viewport, uint32 Value);
};
