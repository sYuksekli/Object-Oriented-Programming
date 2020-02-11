#ifndef GTUVECTOR_H_
#define GTUVECTOR_H_

#include "GTUContainer.cpp"

namespace GtuSTL{

	template <class T>
	class GTUVector : public GTUContainer<T>
	{

	public:
		GTUVector();
		GTUVector(int Capacity);
		bool empty() const noexcept(true) override;
		int size() const noexcept(true) override;
		int max_size() const noexcept(true) override;
		GTUIterator<T> insert(const GTUIterator<T>& iter, const T& element) noexcept(false) override;
		GTUIterator<T> erase(const GTUIterator<T>& iter) noexcept(true) override;
		void clear() noexcept(true) override;
		GTUIterator<T> begin() noexcept(true) override;
		GTUIterator<T> end() noexcept(true) override;
		T& operator[](int index) noexcept(true);
		const T& operator[](int index) const noexcept(true);
	};

}

#endif