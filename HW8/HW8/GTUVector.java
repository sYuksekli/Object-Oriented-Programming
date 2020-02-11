import java.util.Arrays;
import java.lang.reflect.Array;
import java.lang.Class;
import java.lang.IllegalArgumentException;
import java.util.NoSuchElementException;


public class GTUVector<E> extends GTUContainer<E>
{

	/**
	* If the capacity is full, It expands the vector.
	*/
	private void increaseCapacity()
	{	
		capacity *= 2;
		container = Arrays.copyOf(container,capacity);
	}

	/**
	* Inner class for customized iterator of vector.
	*/
	private class vectorIterator extends GTUConcreteIterator<E>
	{	
		/**
		* No parameter constructor
		*/
		private vectorIterator()
		{
			super();
			_container = container;
			_size = size;
		}
	}	

	/**
	* Constructor to initialize the capacity of the vector to 100 by default.
	*/
	public GTUVector(Class<E[]> _type)
	{
		super(_type);
	}

	/**
	* Constructor to initalize fields according to given parameters.
	*/
	public GTUVector(int _capacity, Class<E[]> _type)
	{
		super(_capacity,_type);
	}


	/**
	* Inserts the given element into the vector.
	* @return true, if the operation is successful.
	* @throws IllegalArgumentException
	*/
	public boolean insert(E element) throws IllegalArgumentException
	{	

		if (element == null) {
			throw new IllegalArgumentException();
		}

		int oldSize = size;
		
		if (size == capacity) {
			increaseCapacity();
		}

		container[size] = element;
		++size;

		// If size does not change, it means operation is not successful. 
		if (oldSize != size){
			return true;
		}

		return false;
	}

	/**
	* Removes the given element.
	* @return true, if the operation is successful.
	*/
	public boolean erase(E element)
	{	
		int oldSize = size;
		
		for (int i=0; i<size; ++i ){ 
			if (container[i] == element){
				-- size;
				for (int j=i; j<size; ++j) {
					container[j] = container[j+1];
				}

				if (size != oldSize )
					return true;
			}
		}
		
		// If size does not change, it means operation is not successful. 
		return false;
	}

	/**
	* Returns an iterator to the beginning of the vector.
	*/
	public GTUConcreteIterator<E> iterator()
	{	
		vectorIterator iterator = new vectorIterator();
		return iterator;
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

		return String.format("Total capacity is %d, Size of the vector is %d ,Elements in the container are %s",capacity, size, elements);
	}

}