// CrazyTanks game, @kusstas 2018. All Rights Reserved.

#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

// 2D vector (x & y axis)
template <typename T>
struct Vector2D
{
    T x;
    T y;

    Vector2D();
    Vector2D(T x, T y);
    Vector2D(const Vector2D<T>& vector2);

    Vector2D<T> operator + (const Vector2D<T>& vector) const;
    Vector2D<T> operator - (const Vector2D<T>& vector) const;
    Vector2D<T> operator * (float scale) const;

    const Vector2D<T>& operator += (const Vector2D<T>& vector);
    const Vector2D<T>& operator -= (const Vector2D<T>& vector);
    const Vector2D<T>& operator *= (float scale);

    bool operator == (const Vector2D<T>& vector) const;

    float getLength() const;

    static Vector2D<T> zeroVector;
};

// Float vector 2d
typedef Vector2D<float> FVector2D;

// Int vector 2d
typedef Vector2D<int> DVector2D;

template <typename T>
Vector2D<T>::Vector2D() : x(T()), y(T())
{
}

template <typename T>
Vector2D<T>::Vector2D(T x, T y) : x(x), y(y)
{
}

template <typename T>
Vector2D<T>::Vector2D(const Vector2D<T>& vector2d) : x(vector2d.x), y(vector2d.y)
{
}

template <typename T>
Vector2D<T> Vector2D<T>::operator + (const Vector2D<T>& vector2d) const
{
    return Vector2D<T>(x + vector2d.x, y + vector2d.y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator - (const Vector2D<T>& vector2d) const
{
    return Vector2D<T>(x - vector2d.x, y - vector2d.y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator * (float scale) const
{
    return Vector2D<T>(static_cast<T>(x * scale), static_cast<T>(y * scale));
}

template <typename T>
const Vector2D<T>& Vector2D<T>::operator += (const Vector2D<T>& vector2d)
{
    *this = *this + vector2d;
    return *this;
}

template <typename T>
const Vector2D<T>& Vector2D<T>::operator -= (const Vector2D<T>& vector2d)
{
    *this = *this - vector2d;
    return *this;
}

template <typename T>
const Vector2D<T>& Vector2D<T>::operator *= (float scale)
{
    *this = *this * scale;
    return *this;
}

template <typename T>
bool Vector2D<T>::operator == (const Vector2D<T>& vector) const
{
    return x == vector.x && y == vector.y;
}

template <typename T>
float Vector2D<T>::getLength() const
{
    float length = sqrt(static_cast<float>(x * x + y * y));
    return length;
}

#endif // !VECTOR_H