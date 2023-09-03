#include "cvec.h"
#include <cmath>
#include <cstdio>

cVec cVecCtor(double x, double y) {
    return {x, y};
}

void cVecDtor(cVec *vec) {
    vec->x = NAN;
    vec->y = NAN;
}

void cVecDump(const cVec *vec) {
    printf("[VEC] = {.x=%d, .y=%d}\n", vec->x, vec->y);
}