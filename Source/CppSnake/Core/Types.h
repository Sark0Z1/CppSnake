// CppSnake. Copyright SarkOZ1. All Right Reserved.

#pragma once

#include "CoreMinimal.h"

namespace Snake
{
	struct Dimension
	{
		int32 width;
		int32 heith;
	};

	enum class CellType
	{
		Empty = 0,
		Wall
		// ToDo - Food, Snake
	};

	struct Settings
	{
		Dimension GridSize;
	};
}
