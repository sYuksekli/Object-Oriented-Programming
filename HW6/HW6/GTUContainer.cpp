#include "GTUContainer.h"

namespace GtuSTL
{
	template <class T>
	GTUContainer<T>::GTUContainer()
	{
		capacity = 100;
		_size = 0;
		shared_ptr<T> tmp(new T[capacity], default_delete<T[]>());
		container = tmp;
	}

	template <class T>
	GTUContainer<T>::GTUContainer(int Capacity)
	{
		capacity = Capacity;
		_size = 0;
		shared_ptr<T> tmp(new T[capacity], default_delete<T[]>());
		container = tmp;		
	}
}
