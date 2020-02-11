#include "GTUSet.cpp"
#include "GTUVector.cpp"
#include "GTUIterator.cpp"
#include "GTUIteratorConst.cpp"

#include <iostream>
using namespace std;
using namespace GtuSTL;



namespace
{	
	// Functions to test global functions find, find_if, for_each
	void print(int element);
	void sum(int element);
	void is_even(int element);
	bool isEven(int element);
	bool isPrimeNumber(int element);

	template <class T, class R>
	R for_each(GTUIterator<T> first, GTUIterator<T> last, R function);

	template <class T, class R>
	GTUIterator<T> find_if(GTUIterator<T> first, GTUIterator<T> last, R function);

	template <class T>
	GTUIterator<T> find(GTUIterator<T> first, GTUIterator<T> last, T value);
}



int main(int argc, char const *argv[])
{	

	/**
	// Testing GTUVector class.
	// I also use GTUIterator to test GTUVector class.
	*/

	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  TESTİNG OF FUNCTIONS OF GTUVECTOR CLASS                       " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;


	// Iterator 
	GTUIterator<int> iter;
	// GTUVector container with capacity of 100
	GTUVector<int> vec;

	/* TESTING MAX_SIZE and SIZE FUNCTION GTUVECTOR */
	cout << "Testing of max_size function of GTUVector class. Max size of the vector is " << vec.max_size() << endl;
	cout << endl;
	cout << "Testing of size function of GTUVector class. Size of the vector is " << vec.size() << endl;
	cout << endl;

	/* TESTING BEGIN FUNCTION GTUVECTOR */
	// It points to the beginning of the vector
	iter = vec.begin();

	/* TESTING INSERT FUNCTION GTUVECTOR */
	// Insert elements using iterator position
	// It inserts element to the beginning, because iterator points there
	// It should store elements in the vector like this -> 40,30,20,10
	vec.insert(iter,10);
	vec.insert(iter,20);
	vec.insert(iter,30);
	vec.insert(iter,40);
	

	/* TESTING ++ OPERATOR FOR GTUITERATOR */ 
	// Change iterator position, now it points begin() + 1 and insert new element to this position.
	// It should store elements in the vector like this -> 40,50,30,20,10
	++iter;
	iter = vec.insert(iter,50);
	
	/* TESTING END FUNCTION OF GTUVECTOR */
	// Change position of the iterator, now it points to the end of the container and insert an element.
	// It should store elements in the vector like this -> 40,50,30,20,10,20
	iter = vec.end();
	vec.insert(iter,20);
	

	cout << "Testing of insert, begin, end function of GTUVector class"
		 << " and Testing of ++, != and * operator for GTUIterator." << endl;
	cout << "elements in the vector :" << endl;
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it << endl;
	
	cout << endl;


	/* TESTING ERASE FUNCTION OF GTUVECTOR */
	// Now, iterator points the end of the container, so it should erase last element.
	// It should store elements in the vector like this -> 40,50,30,20,10
	vec.erase(iter);
	// Change the position of the iterator and erase the element that locates in that position.
	// It should store elements in the vector like this -> 40,50,30,20
	--iter;
	vec.erase(iter);

	// new Iterator to test assignment operator 
	// iter2 points to the beginning of the vector, so it should erase the first element in the vector.
	// It should store elements in the vector like this -> 50,30,20
	GTUIterator<int> iter2;
	iter2 = vec.begin();
	iter = iter2;
	vec.erase(iter);
	
	cout << "Testing of == operator of GTUIterator class using iter and iter2" << endl
		 << "If they are equal to each other, it should give us 1" << endl;
	if (iter == iter2)
	{
		cout << "Result: 1" << endl;
	}
	

	cout << endl;
	cout << "Testing of erase, size function and [] operator of GTUVector class"
		 <<	"and Testing of -- and = operator for GTUIterator." << endl;
	cout << "Elements in the vector :" << endl;

	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << endl;

	cout << endl;

	/* TESTING CLEAR and EMPTY FUNCTION OF GTUVECTOR */
	vec.clear();
	cout << "Testing of clear and empty function of GTUVector class" << endl;
	cout <<  "Checking whether container is empty, if it is, it should give us 1." << endl;
	cout << "Result:" << vec.empty() << endl;
	cout << endl;
	

/* ************************************************************************************************ */


	/**
	// Testing GTUSet class.
	// I also use GTUIterator to test GTUSet class.
	*/

	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  TESTİNG OF FUNCTIONS OF GTUSET CLASS                          " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;


	// Iterator 
	GTUIterator<char> iter_;
	// GTUSet container with capacity of 50
	GTUSet<char> set(50);

	/* TESTING MAX_SIZE and SIZE FUNCTION GTUSET */
	cout << "Testing of max_size function of GTUSet class. Max size of the Set is " << set.max_size() << endl;
	cout << endl;
	cout << "Testing of size function of GTUSet class. Size of the Set is " << set.size() << endl;
	cout << endl;

	/* TESTING BEGIN FUNCTION GTUSET */
	// It points to the beginning of the set
	iter_ = set.begin();

	/* TESTING INSERT FUNCTION GTUSET */
	// Insert elements using iterator position
	// It inserts element to the beginning, because iterator points there
	// It should store elements in the set like this -> K,E,B,A
	set.insert(iter_,'A');
	set.insert(iter_,'B');
	set.insert(iter_,'E');
	set.insert(iter_,'K');
	

	/* TESTING ++ OPERATOR FOR GTUITERATOR */ 
	// Change iterator position, now it points begin() + 1 and insert new element to this position.
	// It should store elements in the set like this -> K,S,E,B,A
	++iter_;
	iter_ = set.insert(iter_,'S');
	
	/* TESTING END FUNCTION OF GTUVECTOR */
	// Change position of the iterator, now it points to the end of the container and insert an element.
	// It should store elements in the vector like this -> K,S,E,B,A,F
	iter_ = set.end();
	set.insert(iter_,'F');
	

	cout << "Testing of insert, begin, end function of GTUSet class"
		 << " and Testing of ++, != and * operator for GTUIterator." << endl;
	cout << "Elements in the set :" << endl;
	for (auto it = set.begin(); it != set.end(); ++it)
		cout << *it << endl;

	cout << endl;
	cout << "Testing of exception." 
		 << "Try to add S again" << endl;
	set.insert(iter_,'S');


	/* TESTING ERASE FUNCTION OF GTUSET */
	// Now, iterator points the end of the container, so it should erase last element.
	// It should store elements in the vector like this -> K,S,E,B,A
	set.erase(iter_);
	// Change the position of the iterator and erase the element that locates in that position.
	// It should store elements in the vector like this -> K,S,E,B
	--iter_;
	set.erase(iter_);

	// new Iterator to test assignment operator 
	// iter2 points to the beginning of the vector, so it should erase the first element in the vector.
	// It should store elements in the vector like this -> S,E,B
	GTUIterator<char> iter2_;
	iter2_ = set.begin();
	iter_ = iter2_;
	set.erase(iter_);
	
	cout << endl;
	cout << "Testing of == operator of GTUIterator class using iter_ and iter2_" << endl
		 << "If they are equal to each other, it should give us 1" << endl;
	if (iter_ == iter2_)
	{
		cout << "Result: 1" << endl;
	}
	

	cout << endl;
	cout << "Testing of erase and size function of GTUSet class "
		 <<	"and Testing of -- and = operator for GTUIterator." << endl;
	cout << "Elements in the set :" << endl;

	for (auto it = set.begin(); it != set.end(); ++it)
		cout << *it << endl;

	cout << endl;

	/* TESTING CLEAR and EMPTY FUNCTION OF GTUSET */
	set.clear();
	cout << "Testing of clear and empty function of GTUSet class" << endl;
	cout <<  "Checking whether container is empty, if it is, it should give us 1." << endl;
	cout << "Result:" << set.empty() << endl;
	cout << endl;

	

	/* TESTING -> OPERATOR OF GTUITERATOR */
	set.insert(iter_,'C');
	GTUIterator< GTUSet<char>> setIterator;
	GTUVector< GTUSet<char>> vec_(10);
	setIterator = vec_.begin();
	vec_.insert(setIterator,set);

	cout << "Testing of -> operator of GTUIterator class" << endl;
	cout << "Size of the vec_ is " << setIterator->size() << endl;


/* ************************************************************************************************ */


	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  TESTİNG OF GTUITERATORCONST FUNCTIONS 			                         " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;

	
	GTUVector<int> vector;
	GTUIterator<int> it1;
	it1 = vector.begin();
	vector.insert(it1,1);
	vector.insert(it1,2);
	vector.insert(it1,3);
	vector.insert(it1,4);
	vector.insert(it1,5);

	/* GTUITERATORCONST TESTING*/
	cout << "Testing of GTUIteratorConst class" << endl;

	cout << "It points to the beginning of the vector" << endl;
	int* ptr = &vector[0];
	GTUIteratorConst<int> constIter(ptr);
	cout << "First element in the vector is " << endl;
	cout << *constIter << endl;
	cout << endl;

	cout << "Testing of ++ and * operators" << endl;
	cout << "Second element in the vector is " << endl;
	++constIter;
	cout << *constIter << endl;
	cout << endl;

	cout << "Testing of = and == operators" << endl;
	GTUIteratorConst<int> constIter2 = constIter;
	if (constIter2 == constIter)
	{
		cout << "constIter2 and constIter are equal " << endl;
	}
	cout << endl;

	--constIter2;
	cout << "Testing of --and != operators" << endl;
	if (constIter2 != constIter)
	{
		cout << "constIter2 and constIter are not equal " << endl;
	}
	cout << endl;


	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  TESTİNG OF GLOBAL FUNCTIONS 			                         " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;


	/* TESTING OF FOR_EACH FUNCTION */
	cout << "Testing of for_each function" << endl;
	cout << endl;
	cout << "Elements in the vector are 5,4,3,2,1" << endl;

	cout << "print function is used for testing" << endl;
	for_each(vector.begin(),vector.end(),print);
	cout << endl;
	cout << "is_even function is used for testing" << endl;
	for_each(vector.begin(),vector.end(),is_even);
	cout << endl;
	cout << "sum function is used for testing" << endl;
	for_each(vector.begin(),vector.end(),sum);
	cout << endl;


	/* TESTING OF FIND_IF FUNCTION */
	cout << "Testing of find_if function" << endl;
	cout << endl;
	cout << "isEven function is used for testing" << endl;

	GTUIterator<int> find_if_iterator;
	find_if_iterator = find_if(vector.begin(),vector.end(),isEven);
	cout << "isEven function return true if element is even" << endl
		 << "so find_if function should return an iterator to the first element that is even "
		 << "which is four " << endl;
	cout << "Result: The element that find_if_iterator points is " << *find_if_iterator << endl;
	cout << endl;

	find_if_iterator = find_if(vector.begin(),vector.end(),isPrimeNumber);
	cout << "isPrimeNumber function return true if element is prime number" << endl
		 << "so find_if function should return an iterator to the first element that is prime number "
		 << "which is five " << endl;
	cout << "Result: The element that find_if_iterator points is " << *find_if_iterator << endl;
	cout << endl;


	/* TESTING OF FIND FUNCTION */
	cout << "Testing of find function" << endl;
	cout << endl;

	GTUIterator<int> find_iterator;
	find_iterator = find(vector.begin(),vector.end(),5);
	cout << "5 exists in the vector. Iterator that returned by the function points to " << *find_iterator << endl;
	cout << endl;

	find_iterator = find(vector.begin(),vector.end(),2);
	cout << "2 exists in the vector. "
		 << "Result: Iterator that returned by the function points to " << *find_iterator << endl;
	cout << endl;

	find_iterator = find(vector.begin(),vector.end(),7);
	cout << "7 doesn't exist in the vector. Iterator that returned by the function should point ending of the vector" << endl 
	     << "Result: Iterator that returned by the function points to " << *find_iterator << endl;
	cout << endl;

	return 0;
}


namespace
{
	void print(int element){
		cout << element << endl;
	}

	void sum(int element){
		cout << element+10 << endl;
	}

	void is_even(int element){

		if (element % 2 == 0){
			cout << "This number is even" << endl;
		}
		else{
			cout << "This number is odd" << endl;
		}
	}

	bool isEven(int element){

		if (element % 2 == 0){
			return true;
		}
		else{
			return false;
		}
	}

	bool isPrimeNumber(int element){

		for (int i = 2; i < element; ++i)
		{
			if (element / i == 0)
			{
				return false;
			}
		}

		return true;
	}

	template <class T, class R>
	R for_each(GTUIterator<T> first, GTUIterator<T> last, R function)
	{
		for (auto iter = first; iter != last; ++iter)
			function(*iter);
		
		return function;
	}

	template <class T, class R>
	GTUIterator<T> find_if(GTUIterator<T> first, GTUIterator<T> last, R function)
	{	
		--last;
		int Result;
		GTUIterator<T> iter;
		for (iter = first; iter != last; ++iter){
			Result = function(*iter);
			if(Result == true){
				return iter;
			}
		}

		return iter;
	}

	template <class T>
	GTUIterator<T> find(GTUIterator<T> first, GTUIterator<T> last, T value)
	{	
		--last;
		GTUIterator<T> iter;
		for (iter = first; iter != last; ++iter){
			if(*iter == value){
				return iter;
			}
		}

		return last;
	}

}