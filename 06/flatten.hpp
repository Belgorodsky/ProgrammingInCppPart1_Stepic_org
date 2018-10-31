#pragma once
#include <iostream>


// Весь вывод должен осуществляться в поток out,
// переданный в качестве параметра.
//
// Можно заводить любые вспомогательные функции,
// структуры или даже изменять сигнатуру flatten,
// но при этом все примеры вызова из задания должны
// компилироваться и работать.

template <typename T>
void flatten(const Array< Array<T> > &array, std::ostream& out)
{
    size_t sz = array.size();
    for (size_t i = 0; i != sz; ++i)
        flatten(array[i], out);
}

template <class T>
void flatten(const Array<T> &array, std::ostream& out)
{
    size_t sz = array.size();
    for (size_t i=0;i!=sz;++i)
        out << array[i] << ' ';
}
