#ifndef WAVESYSTEM_H
#define WAVESYSTEM_H

#include "Game_local.h"

class WaveSystem {
private:
    int currentWave;
    bool waveInProgress;
    idList<idEntity*> spawnPoints;  // List of all func_spawner entities

public:
    WaveSystem();
    void Init();
    void StartWave();
    void EnemyDefeated();
    void UpdateHUD();
};

extern WaveSystem waveSystem;

#endif
