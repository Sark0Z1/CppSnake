// CppSnake. Copyright SarkOZ1. All Right Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace Snake
{
	class Grid
	{
	public:
		Grid(const Dimension& dim);

		Dimension dim() const { return c_dim; }

	private:
		const Dimension c_dim;

		TArray<CellType> m_cells;

		void InitWalls();

		void PrintDebug();

		FORCEINLINE int32 PositionIndex(int32 x, int32 y) const;
	};
}
