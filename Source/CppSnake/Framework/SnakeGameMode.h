// CppSnake. Copyright SarkOZ1. All Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CppSnake/Core/Game.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGameMode.generated.h"

class ASpatialGrid;

UCLASS()
class CPPSNAKE_API ASnakeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, meta=(ClampMin = "10", ClampMax="100"))
	FIntPoint GridSize{10,10};

	UPROPERTY(EditDefaultsOnly, meta=(ClampMin = "10", ClampMax="100"))
	int32 CellSize{10};

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpatialGrid> GridVisualClass;

private:
	TUniquePtr<Snake::Game> Game;

	UPROPERTY()
	ASpatialGrid* GridVisual;
};
