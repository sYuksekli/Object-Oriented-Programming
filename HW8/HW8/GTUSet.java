import java.util.Arrays;
import java.lang.reflect.Array;
import java.lang.Class;
import java.util.NoSuchElementException;
import java.lang.IllegalArgumentException;


public class GTUSet<E> extends GTUContainer<E>
{	


	/**
	* If the capacity is full, It expands the set.
	*/
	private void increaseCapacity()
	{
		capacity*=2;
		container = Arrays.copyOf(container,capacity);
	}

	/**
	* Inner class for customized iterator of set.
	*/
	private class SetIterator extends GTUConcreteIterator<E>
	{	
		/**
		* No parameter constructor
		*/
		private SetIterator()
		{
			super();
			_container = container;
			_size = size;
		}
	}

	/**
	* constructor to initialize the capacity of the set to 100 by default.
	*/
	public GTUSet(Class<E[]> _type)
	{
		super(_type);
	}

	/**
	* Constructor to initalize fields according to given parameters.
	*/
	public GTUSet(int _capacity, Class<E[]> _type)
	{
		super(_capacity,_type);
	}


	/**
	* Inserts the given element into the set.
	* @return true, if the operation is successful.
	* @throws IllegalArgumentException
	*/
	public boolean insert(E element) throws IllegalArgumentException
	{	
		int oldSize = size;

		// If the parameter exist in the set
		for (int i=0; i<size; ++i) {
			if (container[i].equals(element)) {
				throw new IllegalArgumentException();
			}
		}

		if (capacity == size) {
			increaseCapacity();
		}

		container[size] = element;
		++ size;

		// If size does not change, it means operation is not successful. 
		if (oldSize != size)
			return true;
		return false;
	}

	/**
	* Removes the given element.
	* @return true, if the operation is successful.
	*/
	public boolean erase(E element)
	{	
		int oldSize = size;

		int position = 0;
		for (int i=0; i<size; ++i) {
			if (container[i] == element) {
				position = i;
			}
		}

		--size;
		for (int i=position; i<size; ++i) {
			container[i] = container[i+1];
		}

		// If size does not change, it means operation is not successful. 
		if (size != oldSize)
			return true;
		return false;
	}


	/**
	* Returns an iterator to the beginning of the set.
	*/
	public GTUConcreteIterator<E> iterator()
	{
		SetIterator setIterator = new SetIterator();
		return setIterator;
	}


	/**
    * It returns a string that textually represents this object.
    * @return a string representation of the object
    */
	public String toString()
	{	
		String elements = "";
		for (int i=0; i<size; ++i) {
			elements += container[i];
			elements += " ";
		}

		return String.format("Total capacity is %d, Size of the set is %d ,Elements in the container are %s",capacity, size, elements);
	}


}