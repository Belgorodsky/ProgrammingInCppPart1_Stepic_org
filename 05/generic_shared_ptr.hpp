#include <cstddef>
#include <algorithm>

struct Expression;
struct Number;
struct BinaryOperation;

struct RefCountBase
{
//	may be also weakptr_counter if needed
	size_t shptr_counter;
};

template<class T>
struct GenericSharedPtr
{
	// реализуйте следующие методы
public:
	explicit GenericSharedPtr(T *ptr = 0) :
		ptr_(ptr), ref_counter_(NULL)
	{
		if (ptr_)
		{
			ref_counter_ = new RefCountBase;
			ref_counter_->shptr_counter = 1;
		}
	}

	~GenericSharedPtr()
	{
		if (ref_counter_ && !--(ref_counter_->shptr_counter))
		{
			delete ref_counter_;
			delete ptr_;
		}
	}

	GenericSharedPtr(const GenericSharedPtr &rhs) :
		ptr_(rhs.ptr_), ref_counter_(rhs.ref_counter_)
	{
		if (ref_counter_)
			++(ref_counter_->shptr_counter);
	}

	GenericSharedPtr& operator=(const GenericSharedPtr &rhs)
	{
		if (this != &rhs) GenericSharedPtr(rhs).swap(*this);
		return *this;
	}

	T* get() const
	{
		return ptr_;
	}

	void reset(T *ptr = 0)
	{
		GenericSharedPtr<T>(ptr).swap(*this);
	}

	T& operator*() const
	{
		return *ptr_;
	}

	T* operator->() const
	{
		return ptr_;
	}

	void swap(GenericSharedPtr &rhs)
	{
		std::swap(ptr_, rhs.ptr_);
		std::swap(ref_counter_, rhs.ref_counter_);
	}

private:
	T *ptr_;
	RefCountBase *ref_counter_;

};


typedef GenericSharedPtr<Expression> SharedPtr;
