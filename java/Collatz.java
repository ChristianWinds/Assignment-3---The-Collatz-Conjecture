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
			long collatzLength = calculateCollatzLength(intToEvaluate,
								    maxCollatzLength);

			// Check if the current integer's Collatz sequence
			// length is greater than zero to prevent storage of
			// invalid Collatz sequence lengths
			if (collatzLength > 0)
			{
				// Check the number of elements in the Collatz
				// length array to retain only the specified
				// quantity of longest Collatz sequence length
				// and integer pairs
				if (arrayQuantity < collatzLengthsToStore)
				{
					putInDescendingArray();
				}
				else
				{
					putInDescendingFullArray();
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

	static void putInDescendingArray (Pair <Long, Long> collatzPair,
					  Pair <Long, Long> [] collatzArray)
	{
		// Precondition:
		// Postcondition:

		// Code from GeeksforGeeks,
		// https://www.geeksforgeeks.org/search-insert-and-delete-in-a-sorted-array/
		// Accessed Saturday, November 30th, 2019
		int i;

		for (i = n - 1;
		     (i >= 0 && arr[i] > key);
		     i--)
		{
			;
		}
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
