#ifndef GTUSET_H_
#define GTUSET_H_

#include "GTUContainer.h"

namespace GtuSTL
{
	template <class T>
	class GTUSet : public GTUContainer<T>
	{

	public:
		GTUSet();
		GTUSet(int Capacity);
		bool empty() const noexcept(true) override;
		int size() const noexcept(true) override;
		int max_size() const noexcept(true) override;
		GTUIterator<T> insert(const GTUIterator<T>& iter, const T& element) noexcept(false) override;
		GTUIterator<T> erase(const GTUIterator<T>& iter) noexcept(true) override;
		void clear() noexcept(true) override;
		GTUIterator<T> begin() noexcept(true) override;
		GTUIterator<T> end() noexcept(true) override;
	};
}


#endif
