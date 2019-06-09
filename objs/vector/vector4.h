#pragma once

#include <iostream>

namespace mut
{
template <typename T>
struct vector4
{
	static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

	T x, y, z, w;

	const static vector4<float> Right;
	const static vector4<float> Forward;
	const static vector4<float> Depth;
	const static vector4<float> W;

	vector4<T>();
	vector4<T>(const T x, const T y, const T z, const T w);

private:
	vector4<T> &Add(const vector4<T> &other);
	vector4<T> &Subtract(const vector4<T> &other);
	vector4<T> &Multiply(const vector4<T> &other);
	vector4<T> &Divide(const vector4<T> &other);

public:
	//template <typename T>
	friend vector4<T> operator+(vector4<T> left, const vector4<T> &right);
	//template <typename T>
	friend vector4<T> operator-(vector4<T> left, const vector4<T> &right);
	//template <typename T>
	friend vector4<T> operator*(vector4<T> left, const vector4<T> &right);
	//template <typename T>
	friend vector4<T> operator/(vector4<T> left, const vector4<T> &right);

	//template <typename T>
	friend vector4<T> &operator+=(vector4<T> &left, const vector4<T> &right);
	//template <typename T>
	friend vector4<T> &operator-=(vector4<T> &left, const vector4<T> &right);
	//template <typename T>
	friend vector4<T> &operator*=(vector4<T> &left, const vector4<T> &right);
	//template <typename T>
	friend vector4<T> &operator/=(vector4<T> &left, const vector4<T> &right);

	//template <typename T>
	friend bool operator==(const vector4<T> &left, const vector4<T> &right);
	//template <typename T>
	friend bool operator!=(const vector4<T> &left, const vector4<T> &right);

	//template <typename T>
	friend std::ostream &operator<<(std::ostream &stream, const vector4<T> &vector);
};
/*
const vector4<float> vector4<float>::Right = vector4<float>(1, 0, 0, 0);
const vector4<float> vector4<float>::Forward = vector4<float>(0, 1, 0, 0);
const vector4<float> vector4<float>::Depth = vector4<float>(0, 0, 1, 0);
const vector4<float> vector4<float>::W = vector4<float>(0, 0, 1, 0);
*/
} // namespace mut