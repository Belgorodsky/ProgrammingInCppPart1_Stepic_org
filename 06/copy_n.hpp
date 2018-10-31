#pragma once
#include <cstddef>

// Параметры функции copy_n идут в следующем
// порядке:
//   1. целевой массив
//   2. массив источник
//   3. количество элементов, которые нужно
//      скопировать
//
// Вам нужно реализовать только функцию copy_n,
// чтобы ее можно было вызвать так, как показано
// в примере.

// put your code here
template <class T, class F>
void copy_n(T *to, const F *from, size_t count)
{
    while (count--)
        *to++ = (T)*from++;
}
