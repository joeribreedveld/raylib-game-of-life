#include <stdlib.h>

#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 512;
    const int screenHeight = 512;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(60);

    /* InitGrid */
    const int gridSize = 32;

    bool **grid = malloc(sizeof(bool *) * gridSize);

    for (int i = 0; i < gridSize; i++) {
        grid[i] = malloc(sizeof(bool) * gridSize);

        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = 0;
        }
    }

    grid[6][9] = 1;

    while (!WindowShouldClose()) {
        /* Update */

        /* Draw */
        BeginDrawing();

        /* DrawGrid */
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

        ClearBackground(WHITE);

        EndDrawing();
    }

    /* DeInit */
    /* UnloadGrid */
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }

    free(grid);

    CloseWindow();

    return 0;
}