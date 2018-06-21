#include<stdio.h>
#include<math.h>
#include <stdint.h>
const uint8_t NCaloLayer1Eta=17;
const uint8_t NCaloLayer1Phi=4;

// void getTowerPeaks3x4(uint16_t towerETRegions[3][4],uint16_t cEta[5],
                        // uint16_t cPhi[5],uint16_t ClusterDeposits[32], uint16_t ClusterEta[32], uint16_t ClusterPhi[32]);
void TowerPeaks(uint16_t towerET[17][4], uint16_t TowerPhi[30], uint16_t TowerEta[30]);	 