#pragma once
#include <algorithm>
// Эти классы реализовывать заново не нужно
struct ICloneable;

// Поле data_ типа T в классе ValueHolder
// открыто, к нему можно обращаться
template <typename T>
struct ValueHolder;

// Это класс, который вам нужно реализовать
class Any
{
    public:
    // В классе Any должен быть конструктор,
    // который можно вызвать без параметров,
    // чтобы работал следующий код:
    //    Any empty; // empty ничего не хранит
    Any() : ptr(NULL) {}

    // В классе Any должен быть шаблонный
    // конструктор от одного параметра, чтобы
    // можно было создавать объекты типа Any,
    // например, следующим образом:
    //    Any i(10); // i хранит значение 10
    template<class T>
        Any(const T& t) : ptr(new ValueHolder<T>(t)) {}

    // Не забудьте про деструктор. Все выделенные
    // ресурсы нужно освободить.
    ~Any() { delete ptr; }

    // В классе Any также должен быть конструктор
    // копирования (вам поможет метод clone
    // интерфейса ICloneable)
    Any(const Any&rhs) : ptr(rhs.ptr ? rhs.ptr->clone() : rhs.ptr) {}

    // В классе должен быть оператор присваивания и/или
    // шаблонный оператор присваивания, чтобы работал
    // следующий код:
    //    Any copy(i); // copy хранит 10, как и i
    //    empty = copy; // empty хранит 10, как и copy
    //    empty = 0; // а теперь empty хранит 0
    Any &operator=(const Any &rhs)
    {
        if (&rhs != this)
        {
            Any(rhs).swap(*this);
        }
        return *this;
    }

    void swap(Any &rhs)
    {
        std::swap(ptr, rhs.ptr);
    }

    // Ну и наконец, мы хотим уметь получать хранимое
    // значение, для этого определите в классе Any
    // шаблонный метод cast, который возвращает
    // указатель на хранимое значение, или нулевой
    // указатель в случае несоответствия типов или
    // если объект Any ничего не хранит:
    //    int *iptr = i.cast<int>(); // *iptr == 10
    //    char *cptr = i.cast<char>(); // cptr == 0,
    //        // потому что i хранит int, а не char
    //    Any empty2;
    //    int *p = empty2.cast<int>(); // p == 0
    // При реализации используйте оператор dynamic_cast.
    template <class T>
        T* cast()
    {
        if (ptr)
        {
            ValueHolder<T>* vh_ptr = dynamic_cast<ValueHolder<T>* >(ptr);
            if (vh_ptr)
                return &(vh_ptr->data_);
        }
        return NULL;
    }
    //
    // Допустим у вас есть два наследника класса Base: Derived1
    // и Derived2. Кроме того у вас есть указать baseptr
    // типа Base*. Как проверить указывает ли этот указатель на
    // самом деле на объект класса Derived1 или на объект
    // класса Derived2? Для этого можно воспользоваться dynamic_cast-ом:
    //
    // Derived1 *derived1ptr = dynamic_cast<Derived1*>(baseptr);
    //
    // Если derived1ptr не равен 0, то  baseptr на самом деле
    // указывал на объект класса Derived1, если же derivedptr равен 0,
    // то baseptr на самом деле указывал на объкт какого-то другого
    // класса (например, Derived2). Это можно проверить так:
    //
    // Derived2 *derived2ptr = dynamic_cast<Derived2*>(baseptr);
    //
    // dynamic_cast работает только, если в классе есть хотя бы
    // один виртуальный метод, и в шаблоне ValueHolder такой
    // как раз имеется.
    private:
    ICloneable *ptr;
};
