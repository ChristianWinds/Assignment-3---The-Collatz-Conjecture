/* Programmer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

import javafx.util.Pair;

public class Collatz
{
	static void storeCollatzInfo(int collatzLengthsToStore,
				     long maxIntToEvaluate)
	{
		// Precondition:
		// Postcondition:

		// Create an integer variable to track the number of items in
		// the Collatz length array
		int arrayQuantity = 0;

		for (long intToEvaluate = 1;
		     intToEvaluate <= maxIntToEvaluate;
		     intToEvaluate++)
		{
			// Calculate the Collatz length of the current integer
			// to evaluate to determine whether the current
			// evaluated integer should be stored in the Collatz
			// length array
			long collatzLength = calculateCollatzLength(intToEvaluate,
								    maxCollatzLength);

			// Check if the current integer's Collatz sequence
			// length is greater than zero to prevent storage of
			// invalid Collatz sequence lengths
			if (collatzLength > 0)
			{
				Pair<Long, Long> collatzPair = new Pair<>(collatzLength,
									  intToEvaluate);

				// Check the number of elements in the Collatz
				// length array to retain only the specified
				// quantity of longest Collatz sequence length
				// and integer pairs
				if (arrayQuantity < collatzLengthsToStore)
				{
					putPairInDescendingArray(collatzPair,
								 collatzLengthArray,
								 arrayQuantity);
					arrayQuantity++;
				}
				else
				{
					putPairInDescendingFullArray(collatzPair,
								     collatzLengthArray);
				}

			// End the Collatz sequence length calculations if the
			// maximum specified integer of the integer calculation
			// range was met to avoid an error
			if (integer >= maxIntToEvaluate)
			{
				break;
			}
		}
	}

	static void putPairInDescendingFullArray()
	{
		// Precondition: The pair received by this method 
		// Postcondition:

		;
	}

	// Code from GeeksforGeeks,
	// https://www.geeksforgeeks.org/search-insert-and-delete-in-a-sorted-array/
	// Accessed Saturday, November 30th, 2019
	static void putPairInDescendingArray (Pair <Long, Long> pairToInsert,
					      Pair <Long, Long> [] array,
					      int pairsInArray,
					      int arrayCapacity)
	{
		// Precondition: The array this method receives holds at least
		// one unused slot, that array is sorted in descending order by
		// key value, this method's received quantity of pairs within
		// the received array is a valid non-negative integer, and the
		// pair to insert received by this method holds two valid Long
		// type values
		// Postcondition:

		// Retrieve the key of the pair to insert to determine where the
		// pair to insert should be placed within the pair array
		Long keyToInsert = pairToInsert.getKey();

		int arrayIndex;

		for (arrayIndex = pairsInArray - 1;
		     (arrayIndex >= 0 && array[arrayIndex].getKey() < keyToInsert);
		     arrayIndex--)
		{
			// Shift the contents within the array to open a slot to
			// place the pair to insert within the array in
			// descending sorted order
			array[arrayIndex + 1] = array[arrayIndex];
		}

		array[arrayIndex + 1] = pairToInsert;
	}

	public static void main()
	{
		// Create an integer variable to determine the number of Collatz
		// sequence lengths to store
		int collatzLengthsToStore = 10;

		Pair <Long, Long> [] collatzLengthArray = new Pair <Long, Long>[collatzLengthsToStore];

		// Create a long variable to determine the maximum permitted
		// Collatz sequence length to store
		long maxCollatzLength = 5000000000L;

		// Create a long variable to designate the maximum integer to
		// receive a Collatz sequence length calculation
		long maxIntToEvaluate = Long.MAX_VALUE;

		// Calculate the Collatz sequence lengths of the positive
		// primitive integer range to determine the longest Collatz
		// sequence lengths
		storeCollatzInfo();
	}
}
