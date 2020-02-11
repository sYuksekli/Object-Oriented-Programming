#include "GTUIterator.h"

namespace GtuSTL {

	template <class T>
	GTUIterator<T>::GTUIterator() noexcept(true){

		// Empty
	}

	template <class T>
	GTUIterator<T>::GTUIterator(T* iter) noexcept(true){

		iterator = iter;
	}

	template <class T>
	T& GTUIterator<T>::operator*() noexcept(true){

		return *iterator;
	}

	template <class T>
	T* GTUIterator<T>::operator->() noexcept(true){

		return iterator;
	}

	template <class T>
	const GTUIterator<T>& GTUIterator<T>::operator++() noexcept(true){

		++iterator;
		return *this;
	}

	template <class T>
	const GTUIterator<T>& GTUIterator<T>::operator--() noexcept(true){

		--iterator;
		return *this;
	}

	template <class T>
	const GTUIterator<T>& GTUIterator<T>::operator=(const GTUIterator& rightSide) noexcept(true){

		iterator = rightSide.iterator;
		return *this;
	}

	template <class T>
	bool GTUIterator<T>::operator==(const GTUIterator& other) const noexcept(true){

		if (iterator == other.iterator)
			return true;
		return false;
	}

	template <class T>
	bool GTUIterator<T>::operator!=(const GTUIterator& other) const noexcept(true){

		return !(*this == other);
	}


}