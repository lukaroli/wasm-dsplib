#ifndef __WINDOW_FUNCTIONS_H__
#define __WINDOW_FUNCTIONS_H__

#include <stdint.h>

void window_blackamn_f64(double window[], uint32_t len);
void window_blackamn_f32(float window[], uint32_t len);

#endif //__WINDOW_FUNCTIONS_H__