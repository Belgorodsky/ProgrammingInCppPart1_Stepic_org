#pragma once
#include <cstddef>
#include <algorithm>

template <typename T>
class Array
{
    public:
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Если у класса нет конструктора
    //   по умолчанию, то второй аргумент этого конструктора
    //   обязателен.
    explicit Array(size_t size, const T& value = T()) 
        : m_size(size), m_ptr(reinterpret_cast<T*>(new char[sizeof(T)*m_size]))
        {
            for (size_t i = 0; i != m_size; ++i)
                new(m_ptr+i)T(value);
        }
    //   конструктор класса, который можно вызвать
    //   без параметров. Должен создавать пустой
    //   Array.
    Array() : m_size(0), m_ptr(NULL) {}
    
    //   конструктор копирования, который создает
    //   копию параметра. Для типа T оператор
    //   присваивания не определен.
    Array(const Array &rhs)
        : m_size(rhs.m_size), m_ptr(reinterpret_cast<T*>(new char[sizeof(T)*m_size]))
        {
            for (size_t i = 0; i != m_size; ++i)
                new(m_ptr+i)T(rhs.m_ptr[i]);
        }

    ~Array()
    {
        for (size_t i = 0; i != m_size; ++i)
            m_ptr[i].~T();
        delete[] reinterpret_cast<char*>(m_ptr);
    }

    void swap(Array &other)
    {
        std::swap(m_size, other.m_size);
        std::swap(m_ptr, other.m_ptr);
    }
    
    //   оператор присваивания.
    Array& operator=(const Array &rhs)
    {
        if (&rhs != this)
            Array(rhs).swap(*this);
        return *this;
    }
    
    //   возвращает размер массива (количество
    //                              элементов).
    size_t size() const
    {
        return m_size;
    }
    
    T& operator[](size_t i)
    {
        return m_ptr[i];
    }
    
    const T& operator[](size_t i) const
    {
        return m_ptr[i];
    }
    
    private:
        size_t m_size;
        T *m_ptr;
};
