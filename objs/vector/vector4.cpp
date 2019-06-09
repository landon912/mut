#include "vector4.h"

namespace mut
{
template <typename T>
vector4<T>::vector4()
{
	x = static_cast<T>(0);
	y = static_cast<T>(0);
	z = static_cast<T>(0);
	w = static_cast<T>(0);
}

template <typename T>
vector4<T>::vector4(const T x, const T y, const T z, const T w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

template <typename T>
vector4<T> &vector4<T>::Add(const vector4<T> &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;

	return *this;
}

template <typename T>
vector4<T> &vector4<T>::Subtract(const vector4<T> &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;

	return *this;
}

template <typename T>
vector4<T> &vector4<T>::Multiply(const vector4<T> &other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;

	return *this;
}

template <typename T>
vector4<T> &vector4<T>::Divide(const vector4<T> &other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;

	return *this;
}

template <typename T>
vector4<T> operator+(vector4<T> left, const vector4<T> &right)
{
	left.Add(right);
	return left;
}

template <typename T>
vector4<T> operator-(vector4<T> left, const vector4<T> &right)
{
	left.Subtract(right);
	return left;
}

template <typename T>
vector4<T> operator*(vector4<T> left, const vector4<T> &right)
{
	left.Multiply(right);
	return left;
}

template <typename T>
vector4<T> operator/(vector4<T> left, const vector4<T> &right)
{
	left.Divide(right);
	return left;
}

template <typename T>
vector4<T> &operator+=(vector4<T> &left, const vector4<T> &right)
{
	vector4<T> returnVector(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
	left = returnVector;
	return left;
}

template <typename T>
vector4<T> &operator-=(vector4<T> &left, const vector4<T> &right)
{
	vector4<T> returnVector(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
	left = returnVector;
	return left;
}

template <typename T>
vector4<T> &operator*=(vector4<T> &left, const vector4<T> &right)
{
	vector4<T> returnVector(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
	left = returnVector;
	return left;
}

template <typename T>
vector4<T> &operator/=(vector4<T> &left, const vector4<T> &right)
{
	vector4<T> returnVector(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
	left = returnVector;
	return left;
}

template <typename T>
bool operator==(const vector4<T> &left, const vector4<T> &right)
{
	return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w);
}

template <typename T>
bool operator!=(const vector4<T> &left, const vector4<T> &right)
{
	return !(left == right);
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector4<T> &vector)
{
	stream << "vector4: (" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << ")";
	return stream;
}
} // namespace mut