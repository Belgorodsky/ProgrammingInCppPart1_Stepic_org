#pragma once
#include <cstddef>
#include <algorithm>

template <typename T>
class Array
{
    public:
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    explicit Array(size_t size = 0, const T& value = T()) 
        : m_size(size), m_ptr(new T[m_size])
        {
            std::fill_n(m_ptr, size, value);
        }
    
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    Array(const Array &rhs)
        : m_size(rhs.m_size), m_ptr(new T[m_size])
        {
            std::copy_n(rhs.m_ptr, m_size, m_ptr);
        }

    ~Array()
    {
        delete[] m_ptr;
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
