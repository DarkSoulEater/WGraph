#include "Matrix3x3.h"
#include <iostream>

void Matrix3x3::Dump() {
    printf("{{%f, %f, %f}"
           " {%f, %f, %f}"
           " {%f, %f, %f}}\n",
           data_[0][0], data_[0][1], data_[0][2],
           data_[1][0], data_[1][1], data_[1][2],
           data_[2][0], data_[2][1], data_[2][2]);
}

Vector3 operator*(const Vector3 &lhs, const Matrix3x3 &rhs) {
    return Vector3(lhs.X * rhs.data_[0][0] + lhs.Y * rhs.data_[1][0] + lhs.Z * rhs.data_[2][0],
                   lhs.X * rhs.data_[0][1] + lhs.Y * rhs.data_[1][1] + lhs.Z * rhs.data_[2][1],
                   lhs.X * rhs.data_[0][2] + lhs.Y * rhs.data_[1][2] + lhs.Z * rhs.data_[2][2]);
}

Vector3 operator*(const Matrix3x3 &lhs, const Vector3 &rhs) {
     return Vector3(lhs.data_[0][0] * rhs.X + lhs.data_[0][1] * rhs.Y + lhs.data_[0][2] * rhs.Z,
                    lhs.data_[1][0] * rhs.X + lhs.data_[1][1] * rhs.Y + lhs.data_[1][2] * rhs.Z,
                    lhs.data_[2][0] * rhs.X + lhs.data_[2][1] * rhs.Y + lhs.data_[2][2] * rhs.Z);
}
