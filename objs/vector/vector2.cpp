#include "vector2.h"

namespace mut
{
template <typename T>
vector2<T>::vector2()
{
	x = static_cast<T>(0);
	y = static_cast<T>(0);
}

template <typename T>
vector2<T>::vector2(const T x, const T y)
{
	this->x = x;
	this->y = y;
}

template <typename T>
vector2<T> &vector2<T>::Add(const vector2<T> &other)
{
	x += other.x;
	y += other.y;

	return *this;
}

template <typename T>
vector2<T> &vector2<T>::Subtract(const vector2<T> &other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

template <typename T>
vector2<T> &vector2<T>::Multiply(const vector2<T> &other)
{
	x *= other.x;
	y *= other.y;

	return *this;
}

template <typename T>
vector2<T> &vector2<T>::Divide(const vector2<T> &other)
{
	x /= other.x;
	y /= other.y;

	return *this;
}

template <typename T>
vector2<T> operator+(vector2<T> left, const vector2<T> &right)
{
	//left is copy data, so using reference math works great
	left.Add(right);
	return left;
}

template <typename T>
vector2<T> operator-(vector2<T> left, const vector2<T> &right)
{
	//left is copy data, so using reference math works great
	left.Subtract(right);
	return left;
}

template <typename T>
vector2<T> operator*(vector2<T> left, const vector2<T> &right)
{
	//left is copy data, so using reference math works great
	left.Multiply(right);
	return left;
}

template <typename T>
vector2<T> operator/(vector2<T> left, const vector2<T> &right)
{
	//left is copy data, so using reference math works great
	left.Divide(right);
	return left;
}

template <typename T>
vector2<T> &operator+=(vector2<T> &left, const vector2<T> &right)
{
	vector2<T> returnVector(left.x + right.x, left.y + right.y);
	left = returnVector;
	return left;
}

template <typename T>
vector2<T> &operator-=(vector2<T> &left, const vector2<T> &right)
{
	vector2<T> returnVector(left.x - right.x, left.y - right.y);
	left = returnVector;
	return left;
}

template <typename T>
vector2<T> &operator*=(vector2<T> &left, const vector2<T> &right)
{
	vector2<T> returnVector(left.x * right.x, left.y * right.y);
	left = returnVector;
	return left;
}

template <typename T>
vector2<T> &operator/=(vector2<T> &left, const vector2<T> &right)
{
	vector2<T> returnVector(left.x / right.x, left.y / right.y);
	left = returnVector;
	return left;
}

template <typename T>
bool operator==(const vector2<T> &left, const vector2<T> &right)
{
	return (left.x == right.x) && (left.y == right.y);
}

template <typename T>
bool operator!=(const vector2<T> &left, const vector2<T> &right)
{
	return !(left == right);
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const vector2<T> &vector)
{
	stream << "vector2: (" << vector.x << "," << vector.y << ")";
	return stream;
}
} // namespace mut