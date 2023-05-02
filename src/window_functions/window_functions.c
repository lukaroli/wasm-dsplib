#include <jsmath.h>
#include "window_functions.h"

#include <stdint.h>
typedef struct {
    uint32_t u32;
    uint16_t u16;
    float f;
} some_struct_t;

some_struct_t some_struct_init(some_struct_t s) {
    some_struct_t p;
    p.u32 = s.u32 + 1;
    p.u16 = s.u16 + 1;
    p.f = s.f + 1.0f;
    return p;
}


void window_blackamn_f64(double window[], uint32_t len) {
    double a0 = 0.42;
    double a1 = -0.5;
    double a2 = 0.08;
    for (uint32_t i = 0; i < (len - 1); i++) {
        window[i] = a0 + a1 * js_cos(2 * M_PI * i / (len - 1)) + a2 * js_cos(4 * M_PI * i / (len - 1));
    }
    window[len - 1] = window[0];
}

/*
void window_blackman_f32(float window[], uint32_t len) {
    float a0 = 0.42f;
    float a1 = -0.5f;
    float a2 = 0.08f;
    for (uint32_t i = 0; i < (len - 1); i++) {
        window[i] = a0 + a1 * js_cosf(2 * M_PIf * i / (len - 1)) + a2 * js_cos(4 * M_PIf * i / (len - 1));
    }
    window[len - 1] = 0;
}
*/