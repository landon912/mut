#include "vector3.h"

namespace mut
{
template <typename T>
vector3<T>::vector3()
{
	x = static_cast<T>(0);
	y = static_cast<T>(0);
	z = static_cast<T>(0);
}

template <typename T>
vector3<T>::vector3(const T x, const T y, const T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template <typename T>
vector3<T> &vector3<T>::Add(const vector3<T> &other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

template <typename T>
vector3<T> &vector3<T>::Subtract(const vector3<T> &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

template <typename T>
vector3<T> &vector3<T>::Multiply(const vector3<T> &other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;

	return *this;
}

template <typename T>
vector3<T> &vector3<T>::Divide(const vector3<T> &other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;

	return *this;
}

template <typename T>
vector3<T> operator+(vector3<T> left, const vector3<T> &right)
{
	left.Add(right);
	return left;
}

template <typename T>
vector3<T> operator-(vector3<T> left, const vector3<T> &right)
{
	left.Subtract(right);
	return left;
}

template <typename T>
vector3<T> operator*(vector3<T> left, const vector3<T> &right)
{
	left.Multiply(right);
	return left;
}

template <typename T>
vector3<T> operator/(vector3<T> left, const vector3<T> &right)
{
	left.Divide(right);
	return left;
}

template <typename T>
vector3<T> &operator+=(vector3<T> &left, const vector3<T> &right)
{
	//vector3<T> returnVector(left.x + right.x, left.y + right.y, left.z + right.z);
	left.x = left.x + right.x;
	left.y = left.y + right.y;
	left.z = left.z + right.z;
	return left;
}

template <typename T>
vector3<T> &operator-=(vector3<T> &left, const vector3<T> &right)
{
	vector3<T> returnVector(left.x - right.x, left.y - right.y, left.z - right.z);
	left = returnVector;
	return left;
}

template <typename T>
vector3<T> &operator*=(vector3<T> &left, const vector3<T> &right)
{
	vector3<T> returnVector(left.x * right.x, left.y * right.y, left.z * right.z);
	left = returnVector;
	return left;
}

template <typename T>
vector3<T> &operator/=(vector3<T> &left, const vector3<T> &right)
{
	vector3<T> returnVector(left.x / right.x, left.y / right.y, left.z / right.z);
	left = returnVector;
	return left;
}

template <typename T>
bool operator==(const vector3<T> &left, const vector3<T> &right)
{
	return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}

template <typename T>
bool operator!=(const vector3<T> &left, const vector3<T> &right)
{
	return !(left == right);
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector3<T> &vector)
{
	stream << "vector3: (" << vector.x << "," << vector.y << "," << vector.z << ")";
	return stream;
}
}