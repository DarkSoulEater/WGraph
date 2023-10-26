#ifndef ___VECTOR3_H___
#define ___VECTOR3_H___

enum Axis {
    AxisX,
    AxisY,
    AxisZ
};

class Vector3 {
public:
    Vector3() : X(0.f), Y(0.f), Z(0.f) {}
    Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
    explicit Vector3(float val) : X(val), Y(val), Z(val) {}
    ~Vector3() = default;

    friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
    friend Vector3 operator*(const Vector3& vec, float factor);
    friend Vector3 operator*(float factor, const Vector3& vec);

    Vector3 operator-() const;
    
    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(const Vector3& other);
    Vector3& operator*=(float factor);
    Vector3& operator/=(float factor);

    static float Dot(const Vector3& lhs, const Vector3& rhs);

    static float Lenght(const Vector3& vec);
    static Vector3 Normalize(const Vector3& vec);
    static Vector3 Reflect(const Vector3& vec, const Vector3& normal);

    static inline Vector3 Zero()    { return Vector3( 0.f,  0.f,  0.f); }
    static inline Vector3 One()     { return Vector3( 1.f,  1.f,  1.f); }
    static inline Vector3 Up()      { return Vector3( 0.f,  1.f,  0.f); }
    static inline Vector3 Down()    { return Vector3( 0.f, -1.f,  0.f); }
    static inline Vector3 Right()   { return Vector3( 1.f,  0.f,  0.f); }
    static inline Vector3 Left()    { return Vector3(-1.f,  0.f,  0.f); }
    static inline Vector3 Forward() { return Vector3( 0.f,  0.f,  1.f); }
    static inline Vector3 Back()    { return Vector3( 0.f,  0.f, -1.f); }

    static Vector3 Rotate(const Vector3& vec, float angle, Axis axis);
    static Vector3 RotateXY(const Vector3& vec, float angle);
    static Vector3 RotateXZ(const Vector3& vec, float angle);
    static Vector3 RotateYZ(const Vector3& vec, float angle);

    void Dump() const;

public:
    float X, Y, Z;
};

#endif // ___VECTOR3_H___