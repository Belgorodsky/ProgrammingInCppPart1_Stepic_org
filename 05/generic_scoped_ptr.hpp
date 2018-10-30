#pragma once
#include <cstddef>
struct Expression;
struct Number;
struct BinaryOperation;

template<class T>
struct GenericScopedPtr
{
	explicit GenericScopedPtr(T *ptr = NULL) :
	       	ptr_(ptr)
       	{
	}

	~GenericScopedPtr()
	{
		delete ptr_; 
	}

	T* get() const
	{
		return ptr_; 
	}

	T* release() {
		T *ret_val = ptr_;
		ptr_ = NULL; 
		return ret_val;
	}

	void reset(T *ptr = 0)
	{
		delete ptr_;
		ptr_ = ptr;
	}

	T& operator*() const
	{
		return *ptr_;
	}

	T* operator->() const
	{
		return ptr_;
	}

	private:
	// запрещаем копирование GenericScopedPtr
	GenericScopedPtr(const GenericScopedPtr&);
	GenericScopedPtr& operator=(const GenericScopedPtr&);

	T *ptr_;
};

typedef GenericScopedPtr<Expression> ScopedPtr;
