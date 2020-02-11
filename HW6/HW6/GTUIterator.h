#ifndef GTUITERATOR_H_
#define GTUITERATOR_H_

#include <memory>

namespace GtuSTL {


	template <class T>
	class GTUIterator
	{

	public:
		GTUIterator() noexcept(true);
		GTUIterator(T* iter) noexcept(true);
		T& operator*() noexcept(true);
		T* operator->() noexcept(true);
		const GTUIterator<T>& operator++() noexcept(true);
		const GTUIterator<T>& operator--() noexcept(true);
		const GTUIterator<T>& operator=(const GTUIterator& rightSide) noexcept(true);
		bool operator==(const GTUIterator& other) const noexcept(true);
		bool operator!=(const GTUIterator& other) const noexcept(true);

	private:
		T* iterator;
	};
}


#endif
