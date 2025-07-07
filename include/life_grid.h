#ifndef LIFE_GRID_H
#define LIFE_GRID_H

#include <stdbool.h>

static const int gridSize = 32;

typedef bool **Grid;

Grid InitLifeGrid();

void UpdateLifeGrid(Grid grid);

void DrawLifeGrid(Grid grid);

void UnloadLifeGrid(Grid grid);

#endif