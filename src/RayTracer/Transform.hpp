#ifndef ___TRANSFORM_HPP___
#define ___TRANSFORM_HPP___

// #include "Transform.h"

Matrix3x3 Transform::LocalCoordsMatrix() const {
    return {
        axisX_.X, axisX_.Y, axisX_.Z,
        axisY_.X, axisY_.Y, axisY_.Z,
        axisZ_.X, axisZ_.Y, axisZ_.Z
    };
}

Matrix3x3 Transform::GlobalCoordsMatrix() const {
    return {
        axisX_.X, axisY_.X, axisZ_.X,
        axisX_.Y, axisY_.Y, axisZ_.Y,
        axisX_.Z, axisY_.Z, axisZ_.Z
    };
}

#endif // ___TRANSFORM_HPP___