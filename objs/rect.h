#pragma once

namespace mut
{
template <typename T>
struct rect
{
	rect(const T &left, const T &right, const T &bottom, const T &top);

	T left, right, top, bottom;
};
} // namespace mut