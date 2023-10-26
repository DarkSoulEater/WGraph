#ifndef ___MATRIX3X3_H___
#define ___MATRIX3X3_H___

#include "Math/Vector3.h"

class Matrix3x3 {
public:
    Matrix3x3(float a00, float a01, float a02, 
              float a10, float a11, float a12,
              float a20, float a21, float a22) : data_({a00, a01, a02, a10, a11, a12, a20, a21, a22}) {}
    ~Matrix3x3() = default;

    friend Vector3 operator*(const Vector3&   lhs, const Matrix3x3& rhs);
    friend Vector3 operator*(const Matrix3x3& lhs, const Vector3& rhs);

    void Dump();
private:
    float data_[3][3];
};

#endif // ___MATRIX3X3_H___