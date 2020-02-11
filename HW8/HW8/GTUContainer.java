import java.lang.IllegalArgumentException;
import java.lang.reflect.Array;
import java.util.Arrays;


public abstract class GTUContainer<E> implements Container<E>
{	

	protected int size;
	protected int capacity;
	protected E [] container;
	protected Class<E[]> type;


	/**
	* Constructor 
	*/
	GTUContainer(Class<E[]> _type)
	{
		capacity = 100;
		size = 0;
		type = _type;
		container = type.cast(Array.newInstance(type.getComponentType(),capacity));
	}

	/**
	* Constructor
	*/
	GTUContainer(int _capacity,Class<E[]> _type)
	{
		capacity = _capacity;
		size = 0;
		type = _type;
		container = type.cast(Array.newInstance(type.getComponentType(),capacity));
	}

	/**
	* Returns true if the container is empty.
	*/
	public boolean empty()
	{
		return (size==0);
	}

	/**
	* Returns the capacity of the container.
	*/
	public int max_size()
	{
		return capacity;
	}

	/**
	* Returns the number of used space of the container.
	*/
	public int size()
	{
		return size;
	}

	/**
	* Clears all the elements in the container.
	*/
	public void clear()
	{
		size = 0;
		E [] temp = type.cast(Array.newInstance(type.getComponentType(),capacity));
		container = Arrays.copyOf(temp,capacity);
	}

	
	/**
	* Returns true if the specified element is in the collection.
	*/
	public boolean contains(Object o)
	{
		for (Object obj : container) {
			if(obj == o){
				return true;
			}
		}

		return false;
	}

	/**
	* Inserts the given element into the container.
	* @return true, if the operation is successful.
	* @throws IllegalArgumentException
	*/
	public abstract boolean insert(E element) throws IllegalArgumentException;

	/**
	* Removes the given element.
	* @return true, if the operation is successful.
	*/
	public abstract boolean erase(E element);

	/**
	* Returns an iterator to the beginning of the container.
	*/
	public abstract GTUConcreteIterator<E> iterator();

	
}