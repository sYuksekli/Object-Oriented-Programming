#ifndef GTUITERATORCONST_H_
#define GTUITERATORCONST_H_

#include <memory>
namespace GtuSTL {


	template <class T>
	class GTUIteratorConst
	{

	public:
		GTUIteratorConst() noexcept(true);
		GTUIteratorConst(T* iter) noexcept(true);
		const T& operator*() const noexcept(true);
		const T* operator->() const noexcept(true);
		const GTUIteratorConst<T>& operator++() noexcept(true);
		const GTUIteratorConst<T>& operator--() noexcept(true);
		const GTUIteratorConst<T>& operator=(const GTUIteratorConst& rightSide) noexcept(true);
		bool operator==(const GTUIteratorConst& other) const noexcept(true);
		bool operator!=(const GTUIteratorConst& other) const noexcept(true);

	private:
		T* const_iterator;
	};
}

#endif
