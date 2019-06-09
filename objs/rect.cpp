#include "rect.h"

namespace mut
{
template <typename T>
rect<T>::rect(const T &left, const T &right, const T &bottom, const T &top)
{
	this->left = left;
	this->right = right;
	this->bottom = bottom;
	this->top = top;
}
} // namespace mut