// CppSnake. Copyright SarkOZ1. All Right Reserved.


#include "CppSnake/Core/Grid.h"

DEFINE_LOG_CATEGORY_STATIC(LogGrid, All, All);

using namespace Snake;

Grid::Grid(const Dimension& dim) : c_dim(Dimension{dim.width + 2, dim.width + 2})
{
	m_cells.Init(CellType::Empty, c_dim.width * c_dim.heith);
	InitWalls();
	PrintDebug();
}


void Grid::InitWalls()
{
	for (int32 y = 0; y < c_dim.heith; ++y)
	{
		for (int32 x = 0; x < c_dim.width; ++x)
		{
			if (x == 0 || x == c_dim.width - 1 || y == 0 || y == c_dim.heith - 1)
			{
				m_cells[PositionIndex(x, y)] = CellType::Wall;
			}
		}
	}
}

void Grid::PrintDebug()
{
#if !UE_BUILD_SHIPPING
	for (int32 y = 0; y < c_dim.heith; ++y)
	{
		FString line;
		for (int32 x = 0; x < c_dim.width; ++x)
		{
			TCHAR symbol{};
			switch (m_cells[PositionIndex(x, y)])
			{
			case CellType::Empty: symbol = '0';
				break;
			case CellType::Wall: symbol = '*';
				break;
			}
			line.AppendChar(symbol).AppendChar(' ');
		}
		UE_LOG(LogGrid, Display, TEXT("%s"), *line);
	}
#endif
}

int32 Grid::PositionIndex(int32 x, int32 y) const
{
	return x + y * c_dim.width;
}
