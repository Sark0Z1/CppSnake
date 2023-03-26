// CppSnake. Copyright SarkOZ1. All Right Reserved.


#include "CppSnake/Framework/SnakeGameMode.h"
#include "CppSnake/Core/Types.h"
#include "CppSnake/Core/Grid.h"
#include "CppSnake/Framework/MainPawn.h"
#include "CppSnake/Enviroment/SpatialGrid.h"

void ASnakeGameMode::StartPlay()
{
	Super::StartPlay();

	// init core game
	const Snake::Settings GS{GridSize.X, GridSize.Y};
	Game = MakeUnique<Snake::Game>(GS);

	// init visual grid
	const FTransform GridOrigin = FTransform::Identity;
	GridVisual = GetWorld()->SpawnActorDeferred<ASpatialGrid>(GridVisualClass, GridOrigin);
	check(GridVisual);
	GridVisual->SetModel(Game->grid(), CellSize);
	GridVisual->FinishSpawning(GridOrigin);

	// set pawn location fitting grid in viewport
	auto* PC = GetWorld()->GetFirstPlayerController();
	auto* Pawn = Cast<AMainPawn>(PC->GetPawn());
	Pawn->UpdateLocation(Game->grid()->dim(), CellSize, GridOrigin);
}
