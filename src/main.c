#include <stdlib.h>

#include "life.h"
#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 512;
    const int screenHeight = 512;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(60);

    Life *life = InitLife();

    while (!WindowShouldClose()) {
        /* Update */
        UpdateLife(life);

        /* Draw */
        BeginDrawing();

        DrawLife(life);

        ClearBackground(WHITE);

        EndDrawing();
    }

    /* DeInit */
    UnloadLife(life);

    CloseWindow();

    return 0;
}