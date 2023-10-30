#ifndef ___FILTERPALETTE_H___
#define ___FILTERPALETTE_H___

#include <assert.h>
#include <vector>
#include "Photoshop/Filter/Filter.h"

class FilterPalette {
public:
    FilterPalette();
    ~FilterPalette();
    
    Filter* GetLastFilter() { return last_filter_; }
    void SetLastFilter(size_t filter_id) { assert(filter_id < GetFilterCount()); last_filter_ = filters_[filter_id]; }

    Filter* GetFilter(size_t filter_id) { assert(filter_id < GetFilterCount()); return filters_[filter_id]; }
    size_t GetFilterCount() const { return filters_.size(); }

private:
    Filter* last_filter_ = nullptr;
    std::vector<Filter*> filters_;
};

#endif // ___FILTERPALETTE_H___