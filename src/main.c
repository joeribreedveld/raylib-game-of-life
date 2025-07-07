#include <stdlib.h>

#include "life_grid.h"
#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 512;
    const int screenHeight = 512;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(60);

    Grid grid = InitLifeGrid();

    while (!WindowShouldClose()) {
        /* Update */
        UpdateLifeGrid(grid);

        /* Draw */
        BeginDrawing();

        DrawLifeGrid(grid);

        ClearBackground(WHITE);

        EndDrawing();
    }

    /* DeInit */
    UnloadLifeGrid(grid);

    CloseWindow();

    return 0;
}