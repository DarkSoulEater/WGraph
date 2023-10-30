#ifndef ___FILTER_H___
#define ___FILTER_H___

#include "Photoshop/Canvas/Canvas.h"
#include "Photoshop/Filter/FilterMask.h"

class Filter {
public:
    Filter() {}

    virtual void ApplyFilter(Canvas& canvas, const FilterMask& mask) {}
};

#endif // ___FILTER_H___