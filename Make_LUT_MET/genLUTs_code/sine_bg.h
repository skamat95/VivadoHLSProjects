#ifndef sineLUTs_h
#define sineLUTs_h
#include <stdint.h>
#define resolution 20.0
int size = 360/resolution;
// SINE LUT
static const float sineLUT[19] = {
  000000,0.34202,0.642788,0.866025,0.984808,0.984808,0.866025,0.642788,0.34202,-8.74228e-08,-0.34202,-0.642788,-0.866025,-0.984808,-0.984808,-0.866025,-0.642788,-0.34202,1.74846e-07,
};
#endif
