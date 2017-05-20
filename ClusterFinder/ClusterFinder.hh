#ifndef ClusterFinder_hh
#define ClusterFinder_hh

#include <stdint.h>

bool ClusterFinder(uint16_t crystals[5][5],
		   uint16_t *preMergePeakEta,
		   uint16_t *preMergePeakPhi,
		   uint16_t *preMergelargeclusterET, uint16_t *preMergesmallclusterET);



#endif
