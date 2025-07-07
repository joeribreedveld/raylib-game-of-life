#ifndef LIFE_H
#define LIFE_H

#include <stdbool.h>

static const int gridSize = 32;

typedef enum {
    LIFE_STATE_RUNNING,
    LIFE_STATE_PAUSED,
} LifeState;

typedef enum {
    LIFE_MODE_DRAWING,
    LIFE_MODE_ERASING,
} LifeMode;

typedef struct Life {
    bool **grid;
    LifeState state;
    LifeMode mode;
} Life;

Life *InitLife();

bool **InitLifeGrid();

void UpdateLife(Life *life);

void DrawLife(Life *life);

LifeState GetLifeState(Life *life);

LifeMode GetLifeMode(Life *life);

void SpawnLifeCell(Life *life, int row, int column);

void KillLifeCell(Life *life, int row, int column);

void StepLife(Life *life);

void UnloadLifeGrid(bool **grid);

void UnloadLife(Life *life);

#endif