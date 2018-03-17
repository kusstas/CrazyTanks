#ifndef VECTOR_H
#define VECTOR_H

template <typename T>

struct Vector2D
{
	T x;
	T y;

	Vector2D() : x(0), y(0) { }
	Vector2D(T x, T y) : x(x), y(y) { }
	Vector2D(const Vector2D<T>& vector) : x(vector.x), y(vector.y) { }

	Vector2D<T> operator + (const Vector2D<T>& vector);
	Vector2D<T> operator - (const Vector2D<T>& vector);
	Vector2D<T> operator * (float scale);

	const Vector2D<T>& operator += (const Vector2D<T>& vector);
	const Vector2D<T>& operator -= (const Vector2D<T>& vector);
	const Vector2D<T>& operator *= (float scale);

};

typedef Vector2D<float> FVector2D;
typedef Vector2D<int> DVector2D;

template <typename T>
Vector2D<T> Vector2D<T>::operator + (const Vector2D<T>& vector)
{
	return Vector2D<T>(x + vector.x, y + vector.y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator - (const Vector2D<T>& vector)
{
	return Vector2D<T>(x - vector.x, y - vector.y);
}

template <typename T>
Vector2D<T> Vector2D<T>::operator * (float scale)
{
	return Vector2D<T>(static_cast<T>(x * scale), static_cast<T>(y * scale));
}

template <typename T>
const Vector2D<T>& Vector2D<T>::operator += (const Vector2D<T>& vector)
{
	*this = *this + vector;
	return *this;
}

template <typename T>
const Vector2D<T>& Vector2D<T>::operator -= (const Vector2D<T>& vector)
{
	*this = *this - vector;
	return *this;
}

template <typename T>
const Vector2D<T>& Vector2D<T>::operator *= (float scale)
{
	*this = *this * scale;
	return *this;
}

#endif // !VECTOR_H