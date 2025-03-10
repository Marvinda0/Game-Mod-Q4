#include "WaveSystem.h"

WaveSystem waveSystem;

WaveSystem::WaveSystem() : currentWave(0), waveInProgress(false) {}

void WaveSystem::Init() {
    idEntity* ent;
    for (ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next()) {
        if (ent->spawnArgs.GetString("classname") == "func_spawner") {
            spawnPoints.Append(ent);  // Store all func_spawner entities
        }
    }

    if (spawnPoints.Num() > 0) {
        gameLocal.Printf("Wave System: Found %d enemy spawners!\n", spawnPoints.Num());
        StartWave();
    }
    else {
        gameLocal.Printf("Wave System: No enemy spawners found!\n");
    }
}

void WaveSystem::StartWave() {
    if (waveInProgress || spawnPoints.Num() == 0) return;

    waveInProgress = true;
    currentWave++;
    gameLocal.Printf("Starting Wave %d!\n", currentWave);

    // Activate all spawners to spawn enemies
    for (int i = 0; i < spawnPoints.Num(); i++) {
        spawnPoints[i]->ProcessEvent(&EV_Activate, this);
    }

    UpdateHUD();
}

void WaveSystem::EnemyDefeated() {
    // Check if all enemies are dead before starting the next wave
    idEntity* ent;
    int aliveEnemies = 0;
    for (ent = gameLocal.spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next()) {
        if (ent->IsType(idAI::Type)) {
            aliveEnemies++;
        }
    }

    if (aliveEnemies == 0) {
        waveInProgress = false;
        gameLocal.ScheduleCall(this, &WaveSystem::StartWave, 5.0f); // 5-second delay for next wave
    }
}

void WaveSystem::UpdateHUD() {
    gameLocal.Printf("Wave: %d\n", currentWave);
}
