#pragma once

#include <iostream>

namespace mut
{
template <typename T>
struct vector3
{
	static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

	T x, y, z;

	vector3<T>();
	vector3<T>(const T x, const T y, const T z);

	const static vector3<float> Right;
	const static vector3<float> Forward;
	const static vector3<float> Depth;

private:
	vector3<T> &Add(const vector3<T> &other);
	vector3<T> &Subtract(const vector3<T> &other);
	vector3<T> &Multiply(const vector3<T> &other);
	vector3<T> &Divide(const vector3<T> &other);

public:
	//template <typename T>
	friend vector3<T> operator+(vector3<T> left, const vector3<T> &right);
	//template <typename T>
	friend vector3<T> operator-(vector3<T> left, const vector3<T> &right);
	//template <typename T>
	friend vector3<T> operator*(vector3<T> left, const vector3<T> &right);
	//template <typename T>
	friend vector3<T> operator/(vector3<T> left, const vector3<T> &right);

	//template <typename T>
	friend vector3<T> &operator+=(vector3<T> &left, const vector3<T> &right);
	//template <typename T>
	friend vector3<T> &operator-=(vector3<T> &left, const vector3<T> &right);
	//template <typename T>
	friend vector3<T> &operator*=(vector3<T> &left, const vector3<T> &right);
	//template <typename T>
	friend vector3<T> &operator/=(vector3<T> &left, const vector3<T> &right);

	//template <typename T>
	friend bool operator==(const vector3<T> &left, const vector3<T> &right);
	//template <typename T>
	friend bool operator!=(const vector3<T> &left, const vector3<T> &right);

	//template <typename T>
	friend std::ostream &operator<<(std::ostream &stream, const vector3<T> &vector);
};

//const vector3<float> vector3<float>::Right = vector3<float>(1, 0, 0);
//const vector3<float> vector3<float>::Forward = vector3<float>(0, 1, 0);
//const vector3<float> vector3<float>::Depth = vector3<float>(0, 0, 1);
} // namespace mut