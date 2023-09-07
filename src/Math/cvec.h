#ifndef ___CVEC_H___
#define ___CVEC_H___

/// @brief 
struct cVec {
    double x, y;
};

/// @brief 
/// @param x 
/// @param y 
/// @return 
cVec cVecCtor(double x, double y);

/// @brief 
/// @param vec 
void cVecDtor(cVec* vec);

/// @brief 
/// @param vec 
void cVecDump(const cVec* vec);

#endif // ___CVEC_H___
