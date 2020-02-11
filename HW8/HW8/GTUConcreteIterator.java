import java.util.NoSuchElementException;

// I create this class, because I don't want my inner iterator class to be public. 
// I create setIterator and vectorIterator classes as private in the GTUvector and GTUSet classes
// I don't want other people to see this nested classes.
// So I use this concrete class in driver.


public class GTUConcreteIterator<E> implements GTUIterator<E>
{
	
	protected int lastReturned;
	protected int currentPosition;

	// I create this fields, because I have to use container and size variables
	// which belong to GTUVector and GTUSet.
	protected E [] _container;
	protected int _size;

	/**
	* Constructor that takes no parameter
	*/
	public GTUConcreteIterator()
	{
		currentPosition = 0;
		lastReturned = -1;
	}

	/**
	* Returns true if the next position is avaliable.
	*/
	public boolean hasNext()
	{
		return (currentPosition<_size);
	}

	/**
	* Returns the next element in the container
	* @throws NoSuchElementException if the next position is not available.
	*/
	public E next() throws NoSuchElementException
	{
		if (!hasNext()) {
			throw new NoSuchElementException();
		}

		++lastReturned;
		E next = _container[currentPosition];
		++currentPosition;
		return next;
	}

}