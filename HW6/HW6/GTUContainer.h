#ifndef GTUCONTAINER_H_
#define GTUCONTAINER_H_

#include <memory>
#include <exception>
#include <iostream>
#include "GTUIterator.h"

using namespace std;

namespace GtuSTL{

	template <class T>
	class GTUContainer{
	
	public:

		GTUContainer();
		GTUContainer(int Capacity);
		virtual bool empty() const noexcept(true) = 0;
		virtual int size() const noexcept(true) = 0;
		virtual int max_size() const noexcept(true) = 0;
		virtual GTUIterator<T> insert(const GTUIterator<T>& iter, const T& element) noexcept(false) = 0;
		virtual GTUIterator<T> erase(const GTUIterator<T>& iter) noexcept(true) = 0;
		virtual void clear() noexcept(true) = 0;
		virtual GTUIterator<T> begin() noexcept(true) = 0;
		virtual GTUIterator<T> end() noexcept(true) = 0;

	protected:
		shared_ptr<T> container;
		int _size;
		int capacity;
	};

}
#endif
