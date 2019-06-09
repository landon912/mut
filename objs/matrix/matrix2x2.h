#pragma once

#include "../vector/vector2.h"

namespace mut
{
template <typename T>
struct matrix2x2
{
	static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

	union {
		T elements[4];

		struct
		{
			vector2<T> columns[2];
		};
	};

	matrix2x2<T>();
	matrix2x2<T>(T diagonal);

	matrix2x2<T> &MultiplyRef(const matrix2x2<T> &other);
	matrix2x2<T> Multiply(const matrix2x2<T> &other);
	vector2<T> Multiply(const vector2<T> &other) const;

	static matrix2x2<T> Inverse(const matrix2x2<T> &matrix);

	//template <typename T>
	friend matrix2x2<T> operator*(const matrix2x2<T> left, const matrix2x2<T> &right)
	{
		return left.Multiply(right);
	}

	//template <typename T>
	friend vector2<T> operator*(const matrix2x2<T> &left, const vector2<T> &right)
	{
		return left.Multiply(right);
	}

	//template <typename T>
	friend matrix2x2<T> &operator*=(matrix2x2<T> &left, const matrix2x2<T> &right)
	{
		return left.MultiplyRef(right);
	}
};
} // namespace mut