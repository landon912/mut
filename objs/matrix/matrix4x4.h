#pragma once

#include "../rect.h"
#include "../vector/vector3.h"
#include "../vector/vector4.h"

namespace mut
{
template <typename T>
struct matrix4x4
{
	static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

	union {
		T elements[16];

		struct
		{
			vector4<T> columns[4];
		};
	};

	matrix4x4<T>();
	matrix4x4<T>(T diagonal);

	matrix4x4<T> &MultiplyRef(const matrix4x4<T> &other);
	matrix4x4<T> Multiply(const matrix4x4<T> &other) const;
	vector3<T> Multiply(const vector3<T> &other) const;
	vector4<T> Multiply(const vector4<T> &other) const;

	static matrix4x4<T> Orthographic(rect<T> rect, T nearClipping, T farClipping);
	static matrix4x4<T> Perspective(T fieldOfView, T aspectRatio, T nearClipping, T farClipping);

	static matrix4x4<T> Translate(const vector3<T> &translation);
	static matrix4x4<T> Rotate(T angle, const vector3<T> &axis);
	static matrix4x4<T> Scale(const vector3<T> &scale);

	matrix4x4<T> &Invert();

	/*static matrix4x4<T> ToWorldSpace();
			static matrix4x4<T> ToLocalSpace();*/

	static matrix4x4<T> Inverse(const matrix4x4<T> &matrix);

	//template <typename T>
	friend matrix4x4<T> operator*(const matrix4x4<T> left, const matrix4x4<T> &right);

	//template <typename T>
	friend vector3<T> operator*(const matrix4x4<T> &left, const vector3<T> &right);

	//template <typename T>
	friend vector4<T> operator*(const matrix4x4<T> &left, const vector4<T> &right);

	//template <typename T>
	friend matrix4x4<T> &operator*=(matrix4x4<T> &left, const matrix4x4<T> &right);
};
} // namespace mut