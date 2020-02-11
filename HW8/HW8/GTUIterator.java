import java.util.NoSuchElementException;


public interface GTUIterator<E>
{	

	/**
	* Returns true if the next position is avaliable.
	*/
	public abstract boolean hasNext();

	/**
	* Returns the next element in the container
	* @throws NoSuchElementException if the next position is not available.
	*/
	public abstract E next() throws NoSuchElementException;

}