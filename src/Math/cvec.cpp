#include "Math/cvec.h"
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
    printf("[VEC] = {.x=%lf, .y=%lf}\n", vec->x, vec->y);
}