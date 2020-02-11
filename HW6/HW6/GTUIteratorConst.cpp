#include "GTUIteratorConst.h"

namespace GtuSTL {

	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst() noexcept(true){

		// Empty
	}

	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst(T* iter) noexcept(true){

		const_iterator = iter;
	}

	template <class T>
	const T& GTUIteratorConst<T>::operator*() const noexcept(true){

		return *const_iterator;
	}

	template <class T>
	const T* GTUIteratorConst<T>::operator->() const noexcept(true){

		return const_iterator;
	}

	template <class T>
	const GTUIteratorConst<T>& GTUIteratorConst<T>::operator++() noexcept(true){

		++const_iterator;
		return *this;
	}

	template <class T>
	const GTUIteratorConst<T>& GTUIteratorConst<T>::operator--() noexcept(true){

		--const_iterator;
		return *this;
	}

	template <class T>
	const GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(const GTUIteratorConst& rightSide) noexcept(true){

		const_iterator = rightSide.const_iterator;
		return *this;
	}

	template <class T>
	bool GTUIteratorConst<T>::operator==(const GTUIteratorConst& other) const noexcept(true){

		if (const_iterator == other.const_iterator)
			return true;
		return false;
	}

	template <class T>
	bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst& other) const noexcept(true){

		return !(*this == other);
	}
}