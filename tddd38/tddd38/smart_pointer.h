/*
* smart_pointer.h     Smart pointer, Step 1
*
* Given member functions have been implemented.
* Class specific swap functions have been added, and used for implementing
* assignment operators in a exception safe and exception  neutral way.
* Assignment operator taking a raw pointer as argument have ben added.
*/
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include <algorithm>
#include <utility>

#include <iostream>

namespace IDA_Smart_Pointer
{

	class smart_pointer
	{
	public:
		smart_pointer() = default;
		explicit smart_pointer(int* p) : ptr_{ p } {}
		smart_pointer(const smart_pointer& other) { copy(other); }
		smart_pointer(smart_pointer&& other) noexcept { swap(other); }
		~smart_pointer() { delete ptr_; }

		//Copy assignment
		smart_pointer& operator=(const smart_pointer& rhs) &
		{
			smart_pointer{ rhs }.swap(*this);
			return *this;
		}

		//move assignment
		smart_pointer& operator=(smart_pointer&& rhs) & noexcept
		{
			if (this != &rhs)
			{
				clear(); //clear this smart_pointer
				swap(rhs); //Steal the contents of the r-value smart_pointer, which will then be empty
			}
			return *this;
		}

		smart_pointer& operator=(int* rhs)
		{
			smart_pointer{ rhs }.swap(*this);
			return *this;
		}

		int& operator*() { return *ptr_; }

		int* operator->() { return ptr_; }

		void swap(smart_pointer& other) { std::swap(ptr_, other.ptr_); } //Swap contents, used for move semantics

	private:

		int* ptr_{ nullptr };

		void copy(const smart_pointer& p)
		{
			ptr_ = (p.ptr_ != nullptr) ? new int{ *p.ptr_ } : nullptr;
		}

		//clear the contents of the smart pointer
		void clear() { delete ptr_; ptr_ = nullptr; }
	};

	template<typename T>
	void swap(smart_pointer& x, smart_pointer& y)
	{
		x.swap(y);
	}

} // namespace IDA_Smart_Pointer

#endif