#include "GTUVector.h"

namespace GtuSTL
{
	// No parameter constructor
	template <class T>
	GTUVector<T>::GTUVector():GTUContainer<T>()
	{
		// Empty
		
	}

	// Constructor to initialize acording to capacity value.
	template <class T>
	GTUVector<T>::GTUVector(int Capacity):GTUContainer<T>(Capacity)
	{
		// Empty
	}

	// Checks whether vector is empty
	template <class T>
	bool GTUVector<T>::empty() const noexcept(true){

		if (this->_size == 0)
			return true;
		return false;
	}

	// Return size of the vector
	template <class T>	
	int GTUVector<T>::size() const noexcept(true){

		return this->_size;
	}

	// Returns the capacity of the vector
	template <class T>
	int GTUVector<T>::max_size() const noexcept(true){

		return this->capacity;
	}

	// Inserts an element according to given parameter. 
	// First parameter indicates the position and second parameter is the value to be inserted.
	// Returns an iterator that points to inserted element.
	template <class T>
	GTUIterator<T> GTUVector<T>::insert(const GTUIterator<T>& iter ,const T& element) noexcept(false){

		try{

			int sizeCounter = 0;

			// If vector is full, allocate new space
			if (this->_size == this->capacity)
			{	
				shared_ptr<T> tmpPtr(new T[this->capacity]);
				for (int i = 0; i < this->_size ; ++i)
					(tmpPtr.get())[i] = (this->container.get())[i];

				this->capacity *= 2;
				shared_ptr<T> tmp(new T[this->capacity], default_delete<T[]>());
				this->container = tmp;
				for (int i = 0; i < this->_size ; ++i)
					(this->container.get())[i] = (tmpPtr.get())[i];
			}

			// If it is the first element to be inserted
			if (this->empty())
			{	
				(this->container.get())[0] = element;
				++this->_size;
				GTUIterator<T> it = begin();
				sizeCounter = 1;

				return it;
			}

			// If not
			else
			{		

				int index = 0;
				GTUIterator<T> it;
				for (it = this->begin(); it != iter; ++it)
					++index;		// Find the position using iterator parameter

				shared_ptr<T> tmpPtr2(new T[this->capacity]);
				for (int i = 0; i < this->_size ; ++i)
					(tmpPtr2.get())[i] = this->container.get()[i];

				(this->container.get())[index] = element;	// Insert new element
				++(this->_size);							// Increase used space
				for (int i = index+1; i < this->_size; ++i){	
					(this->container.get())[i] = (tmpPtr2.get())[i-1]; // Shift every element to right
				}

				sizeCounter = 1;
				return it;
			}

			if (sizeCounter == 0){
				throw invalid_argument("The position that is sended is invalid");
			}

		} catch(invalid_argument& e){

			cerr << "Exception caught:" << e.what() << endl;
		}
	}

	// Erase an element according to the given position.
	template <class T>	
	GTUIterator<T> GTUVector<T>:: erase(const GTUIterator<T>& iter) noexcept(true){

		int index = 0;
		GTUIterator<T> it;
		for (it = this->begin(); it != iter ; ++it)
			++index;		// Find the location of the element to be erased

		--(this->_size); 	// Decrease used space
		for (int i = index; i < this->_size; ++i)
			(this->container.get())[i] = (this->container.get())[i+1]; // Shift every element to left 

		return it;
	
	}

	// Clears the vector
	template <class T>
	void GTUVector<T>::clear() noexcept(true){

		shared_ptr<T> tmp(new T[this->capacity], default_delete<T[]>());	
		// Clear all the element, allocate new space
		this->container = tmp;
		this->_size = 0;	// used space is zero
	}

	// Return an iterator to beginnig of the vector
	template <class T>
    GTUIterator<T> GTUVector<T>::begin() noexcept(true){

		T* tmpPtr = &this->container.get()[0];
		GTUIterator<T> tmpIt(tmpPtr);
		return tmpIt;
	}

	// Return an iterator to the end of the vector
	template <class T>
    GTUIterator<T> GTUVector<T>::end() noexcept(true){

    	T* tmpPtr = &this->container.get()[this->_size];
		GTUIterator<T> tmpIt(tmpPtr);
		return tmpIt;
	}

	// Index operator overloading
	template <class T>
	T& GTUVector<T>::operator[](int index) noexcept(true){

		return (this->container.get())[index];
	}

	// Index operator overloading for const objects
	template <class T>
	const T& GTUVector<T>::operator[](int index) const noexcept(true){

		return (this->container.get())[index];
	}

}