#pragma once
#include <cstddef>

template <typename T>
class Array
{
public:
	explicit Array(size_t size = 0, const T& value = T());
	Array(const Array& other);
	~Array();
	Array& operator=(Array other);
	void swap(Array &other);
	size_t size() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

private:
	size_t size_;
	T *data_;
};

// put your code here
template<class T, class Comp>
T minimum(const Array<T> &arr, Comp comp)
{
    T min = arr[0];
    size_t sz = arr.size();
    while(sz--)
    {
        if (comp(arr[sz],min))
            min = arr[sz];
    }
    return min;
}
