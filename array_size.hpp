#pragma once
#include <cstddef> // size_t

// реализуйте шаблонную функцию array_size,
// которая возвращает значение типа size_t.

template <class T, size_t N>
size_t array_size(T (&arr)[N])
{
	return N;
}
