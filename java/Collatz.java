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

		for (long integer = 1;
		     integer <= maxIntToEvaluate;
		     integer++)
		{
			int collatzLength = calculateCollatzLength(intToEvaluate,
								   maxCollatzLength);

			// Check if the current integer's Collatz sequence
			// length is greater than zero to prevent storage of
			// invalid Collatz sequence lengths
			if (collatzLength > 0)
			{
				// Check the number of elements in the Collatz
				// Length multimap to retain only the specified
				// quantity of longest Collatz sequence length
				// and integer pairs

			// End the Collatz sequence length calculations if the
			// maximum specified integer of the integer calculation
			// range was met to avoid an error
			if (integer >= maxIntToEvaluate)
			{
				break;
			}
		}
	}

	static void putInArraySortDescending (Pair <Long, Long> collatzPair,
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
		// Calculate the Collatz sequence lengths of the positive
		// primitive integer range to determine the longest Collatz
		// sequence lengths
		storeCollatzInfo();
	}
}
