#ifndef TowerFinder_hh
#define TowerFinder_hh

#include <stdint.h>

bool TowerFinder(uint16_t crystals[4][17][5][5], 
		 uint16_t peakEta[4][17],
                 uint16_t peakPhi[4][17],
                 uint16_t largeclusterET[4][17],
                 uint16_t smallclusterET[4][17]);

#endif
