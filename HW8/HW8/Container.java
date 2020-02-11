import java.lang.IllegalArgumentException;

public interface Container<E>
{

	/**
	* Returns true if the container is empty.
	*/
	public abstract boolean empty();

	/**
	* Returns the capacity of the container.
	*/
	public abstract int max_size();

	/**
	* Returns the number of used space of the container.
	*/
	public abstract int size();

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
	* Clears all the elements in the container.
	*/
	public abstract void clear();

	/**
	* Returns an iterator to the beginning of the container.
	*/
	public abstract GTUConcreteIterator<E> iterator();

	/**
	* Returns true if the specified element is in the collection.
	*/
	public abstract boolean contains(Object o);

}