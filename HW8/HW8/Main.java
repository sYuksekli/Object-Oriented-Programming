import java.lang.Class;

public class Main
{
	
	public static void main(String[] args) {
		

		try
		{


			// Testing GTUVector class.
			// I also use GTUconcreteIterator to test GTUVector class.
			System.out.println();
			System.out.println("--------------------------------------------------------------------------------");
			System.out.println("                  TESTİNG OF FUNCTIONS OF GTUVECTOR CLASS                       ");
			System.out.println("--------------------------------------------------------------------------------");
			System.out.println();


			// Iterator 
			GTUConcreteIterator<Integer> iter;
			// GTUVector container with capacity of 100
			GTUVector<Integer> vec = new GTUVector<Integer>(Integer[].class);

			/* TESTING MAX_SIZE and SIZE FUNCTIONS GTUVECTOR */
			System.out.println("Testing of max_size function of GTUVector class. Max size of the vector is "+ vec.max_size());
			System.out.println();
			System.out.println("Testing of size function of GTUVector class. Size of the vector is "+ vec.size());
			System.out.println();


			/* TESTING INSERT FUNCTION OF GTUVECTOR */
			// It should store elements in the vector like this -> 1,2,3,4,5,4,5,6,7,8,9
			vec.insert(1);
			vec.insert(2);
			vec.insert(3);
			vec.insert(4);
			vec.insert(5);
			vec.insert(4);
			vec.insert(5);
			vec.insert(6);
			vec.insert(7);
			vec.insert(8);
			vec.insert(9);


			/* TESTING ITERATOR FUNCTION OF GTUVECTOR */
			// It points to the beginning of the vector
			iter = vec.iterator();

			System.out.println("Testing of insert,iterator,hasNext and next functions of GTUVector and GTUConcreteIterator classes");
			System.out.println("Elements in the vector :");
			while (iter.hasNext()){
				System.out.println(iter.next());
			}
			System.out.println();


			/* TESTING CONTAİNS FUNCTION OF GTUVECTOR */
			System.out.println("Testing contains function of GTUVector class");
			boolean result = vec.contains(2);
			System.out.println("Checking whether vector contains number of 2");
			System.out.println("Result : " + result);

			result = vec.contains(8);
			System.out.println("Checking whether vector contains number of 8 ");
			System.out.println("Result : " + result);

			result = vec.contains(0);
			System.out.println("Checking whether vector contains number of 0");
			System.out.println("Result : " + result);
			System.out.println();


			/* TESTING ERASE FUNCTION OF GTUVECTOR */
			// It should store elements in the vector like this -> 1,3,5,4,5,6,9
			vec.erase(2);
			vec.erase(4);
			vec.erase(7);
			vec.erase(8);
		
			iter = vec.iterator();
			System.out.println("Testing of erase,iterator,hasNext and next functions of GTUVector and GTUConcreteIterator classes");
			System.out.println("Elements in the vector :");
			while (iter.hasNext()){
				System.out.println(iter.next());
			}
			System.out.println();


			/* TESTING CLEAR and EMPTY FUNCTIONS OF GTUVECTOR */
			vec.clear();
			System.out.println("Testing of clear and empty functions of GTUVector class");
			System.out.println("Checking whether container is empty, if it is, it should give us true.");
			System.out.println("Result:" + vec.empty());
			System.out.println();
		


/* ************************************************************************************************ */


		
			// Testing GTUSet class.
			// I also use GTUconcreteIterator to test GTUSet class.
			System.out.println();
			System.out.println("--------------------------------------------------------------------------------");
			System.out.println("                  TESTİNG OF FUNCTIONS OF GTUSET CLASS                       ");
			System.out.println("--------------------------------------------------------------------------------");
			System.out.println();


			// Iterator 
			GTUConcreteIterator<Character> iter2;
			// GTUSet container with capacity of 50
			GTUSet<Character> set = new GTUSet<Character>(50,Character[].class);

			/* TESTING MAX_SIZE and SIZE FUNCTIONS GTUSET */
			System.out.println("Testing of max_size function of GTUSet class. Max size of the set is "+ set.max_size());
			System.out.println();
			System.out.println("Testing of size function of GTUSet class. Size of the set is "+ set.size());
			System.out.println();


			/* TESTING INSERT FUNCTION OF GTUSET */
			// It should store elements in the set like this -> S,I,L,A,B,E,N
			set.insert('S');
			set.insert('I');
			set.insert('L');
			set.insert('A');
			set.insert('B');
			set.insert('E');
			set.insert('N');


			/* TESTING ITERATOR FUNCTION OF GTUSET */
			// It points to the beginning of the set
			iter2 = set.iterator();

			System.out.println("Testing of insert,iterator,hasNext and next functions of GTUSet and GTUConcreteIterator classes");
			System.out.println("Elements in the set :");
			while (iter2.hasNext()){
				System.out.println(iter2.next());
			}
			System.out.println();


			/* TESTING CONTAİNS FUNCTION OF GTUSET */
			System.out.println("Testing contains function of GtuSet class");
			result = set.contains('A');
			System.out.println("Checking whether set contains A letter");
			System.out.println("Result : " + result);

			result = set.contains('Y');
			System.out.println("Checking whether set contains Y letter");
			System.out.println("Result : " + result);

			result = set.contains('B');
			System.out.println("Checking whether set contains B letter");
			System.out.println("Result : " + result);
			System.out.println();


			/* TESTING ERASE FUNCTION OF GTUSET */
			// It should store elements in the set like this -> L,A,E,N
			set.erase('S');
			set.erase('B');
			set.erase('I');
		
			iter2 = set.iterator();
			System.out.println("Testing of erase,iterator,hasNext and next functions of GTUSet and GTUConcreteIterator classes");
			System.out.println("Elements in the set :");
			while (iter2.hasNext()){
				System.out.println(iter2.next());
			}
			System.out.println();


			/* TESTING CLEAR and EMPTY FUNCTIONS OF GTUSET */
			set.clear();
			System.out.println("Testing of clear and empty functions of GTUSet class");
			System.out.println("Checking whether container is empty, if it is, it should give us true.");
			System.out.println("Result:" + set.empty());
			System.out.println();


			/* EXCEPTION TEST */
			// Try yo add same element in the set
			System.out.println("Exception test for set, try to add same element(E) in the set ");
			set.insert('E');
			set.insert('E');

		}

		catch(Exception e)
		{
			System.out.println("Exception caught : " + e);
			System.out.println();
		}

		try
		{
			/* EXCEPTION TEST */
			// Try yo add null element in the vector
			System.out.println("Exception test for vector, try to add invalid element in the vector");
			GTUVector<Integer> vec2 = new GTUVector<Integer>(Integer[].class);
			vec2.insert(null);
		}

		catch(Exception e)
		{
			System.out.println("Exception caught : " + e);
			System.out.println();
		}

	}
}