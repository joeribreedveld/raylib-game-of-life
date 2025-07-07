#include "life_grid.h"

#include <stdlib.h>

#include "raylib.h"

Grid InitLifeGrid() {
    bool **grid = malloc(sizeof(bool *) * gridSize);

    for (int i = 0; i < gridSize; i++) {
        grid[i] = malloc(sizeof(bool) * gridSize);

        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = 0;
        }
    }

    return grid;
}

void UpdateLifeGrid(Grid grid) {}

void DrawLifeGrid(Grid grid) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            /* Temporary */
            DrawRectangleLines(i * (float)GetScreenWidth() / gridSize,
                               j * (float)GetScreenHeight() / gridSize,
                               GetScreenWidth() / gridSize,
                               GetScreenHeight() / gridSize, BLACK);

            if (grid[i][j]) {
                DrawRectangle(i * (float)GetScreenWidth() / gridSize,
                              j * (float)GetScreenHeight() / gridSize,
                              GetScreenWidth() / gridSize,
                              GetScreenHeight() / gridSize, BLACK);
            }
        }
    }
}

void UnloadLifeGrid(Grid grid) {
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }

    free(grid);
}