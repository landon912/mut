#pragma once

#include <iostream>

namespace mut
{
template <typename T>
struct vector2
{
	static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

	T x, y;

	static const vector2<float> Right;
	static const vector2<float> Forward;

	vector2<T>();
	vector2<T>(const T x, const T y);

private:
	vector2<T> &Add(const vector2<T> &other);
	vector2<T> &Subtract(const vector2<T> &other);
	vector2<T> &Multiply(const vector2<T> &other);
	vector2<T> &Divide(const vector2<T> &other);

public:
	//template <typename T>
	friend vector2<T> operator+(vector2<T> left, const vector2<T> &right);
	//template <typename T>
	friend vector2<T> operator-(vector2<T> left, const vector2<T> &right);
	//template <typename T>
	friend vector2<T> operator*(vector2<T> left, const vector2<T> &right);
	//template <typename T>
	friend vector2<T> operator/(vector2<T> left, const vector2<T> &right);

	//template <typename T>
	friend vector2<T> &operator+=(vector2<T> &left, const vector2<T> &right);
	//template <typename T>
	friend vector2<T> &operator-=(vector2<T> &left, const vector2<T> &right);
	//template <typename T>
	friend vector2<T> &operator*=(vector2<T> &left, const vector2<T> &right);
	//template <typename T>
	friend vector2<T> &operator/=(vector2<T> &left, const vector2<T> &right);

	//template <typename T>
	friend bool operator==(const vector2<T> &left, const vector2<T> &right);
	//template <typename T>
	friend bool operator!=(const vector2<T> &left, const vector2<T> &right);

	//template <typename T>
	friend std::ostream &operator<<(std::ostream &stream, const vector2<T> &vector);
};

//const vector2<float> vector2<float>::Right = vector2<float>(1, 0);
//const vector2<float> vector2<float>::Forward = vector2<float>(0, 1);
} // namespace mut