#include "life.h"

#include <stdlib.h>

#include "raylib.h"

Life *InitLife() {
    Life *life = malloc(sizeof(Life));

    life->mode = LIFE_MODE_DRAWING;
    life->state = LIFE_STATE_PAUSED;
    life->grid = InitLifeGrid();

    return life;
}

bool **InitLifeGrid() {
    bool **grid = malloc(sizeof(bool *) * gridSize);

    for (int r = 0; r < gridSize; r++) {
        grid[r] = malloc(sizeof(bool) * gridSize);

        for (int c = 0; c < gridSize; c++) {
            grid[r][c] = 0;
        }
    }

    return grid;
}

void UpdateLife(Life *life) {
    /* Drawing */
    if ((IsMouseButtonDown(MOUSE_BUTTON_LEFT)) &&
        GetLifeState(life) == LIFE_STATE_PAUSED) {
        Vector2 mousePosition = GetMousePosition();

        int row = mousePosition.y / ((float)GetScreenHeight() / gridSize);
        int column = mousePosition.x / ((float)GetScreenWidth() / gridSize);

        if (GetLifeMode(life) == LIFE_MODE_DRAWING) {
            SpawnLifeCell(life, row, column);
        } else if (GetLifeMode(life) == LIFE_MODE_ERASING) {
            KillLifeCell(life, row, column);
        }
    }

    /* Iterating */
    if (IsKeyPressed(KEY_SPACE)) {
        StepLife(life);
    }
}

void DrawLife(Life *life) {
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridSize; c++) {
            if (life->grid[r][c]) {
                DrawRectangle(c * (float)GetScreenWidth() / gridSize,
                              r * (float)GetScreenHeight() / gridSize,
                              GetScreenWidth() / gridSize,
                              GetScreenHeight() / gridSize, BLACK);
            }
        }
    }
}

LifeState GetLifeState(Life *life) { return life->state; }

LifeMode GetLifeMode(Life *life) { return life->mode; }

void SpawnLifeCell(Life *life, int row, int column) {
    if (row > gridSize - 1 || column > gridSize - 1 || row < 0 || column < 0) {
        return;
    }

    life->grid[row][column] = 1;
}

void KillLifeCell(Life *life, int row, int column) {
    if (row > gridSize - 1 || column > gridSize - 1 || row < 0 || column < 0) {
        return;
    }

    life->grid[row][column] = 0;
}

void StepLife(Life *life) {
    bool **oldGrid = life->grid;
    bool **newGrid = InitLifeGrid();

    Vector2 directions[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                            {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridSize; c++) {
            int neighbours = 0;

            for (int i = 0; i < sizeof(directions) / sizeof(directions[0]);
                 i++) {
                int nr = r + (int)directions[i].y;
                int nc = c + (int)directions[i].x;

                if (nr >= 0 && nr < gridSize && nc >= 0 && nc < gridSize) {
                    if (oldGrid[nr][nc]) {
                        neighbours++;
                    }
                }
            }

            if ((neighbours == 2 || neighbours == 3) && oldGrid[r][c]) {
                newGrid[r][c] = 1;
            } else if (neighbours == 3) {
                newGrid[r][c] = 1;
            }
        }
    }

    life->grid = newGrid;

    UnloadLifeGrid(oldGrid);
}

void UnloadLifeGrid(bool **grid) {
    for (int r = 0; r < gridSize; r++) {
        free(grid[r]);
    }

    free(grid);
}

void UnloadLife(Life *life) {
    UnloadLifeGrid(life->grid);

    free(life);
}