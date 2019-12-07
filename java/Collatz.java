/* Programmer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

public class Collatz
{
	static void storeCollatzInfo(int collatzLengthsToStore,
				     long maxIntToEvaluate,
				     long maxCollatzLength)
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
				CollatzInfo collatzPair = new CollatzInfo(collatzLength,
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

	static long calculateCollatzLength(long intToEvaluate,
					   long maxCollatzLength)
	{
		// Precondition: The integer to evaluate and maximum Collatz
		// sequence length received by this function are valid long
		// integers
		// Postcondition: This function delivered the evaluated
		// integer's Collatz sequence length to this function's caller
		// if the sequence length is less than or equal to the maximum
		// permitted Collatz sequence length, or a negative one is
		// returned to this function's caller if the evaluated integer's
		// sequence length exceeds the maximum permitted sequence length

		long collatzLength = 0;

		// Perform the Collatz Conjecture calculations upon the received
		// integer until either the integer equals a value of one, or
		// the Collatz sequence length exceeds the maximum permitted
		// Collatz sequence length
		do
		{
			// Check whether the integer is even or odd to determine
			// which Collatz Conjecture operations should be
			// performed
			if (intToEvaluate % 2 == 0)
			{
				intToEvaluate = intToEvaluate / 2;
			}
			else
			{
				intToEvaluate = (intToEvaluate * 3) + 1;
			}
		} while ((intToEvaluate != 1) &&
			 (collatzLength < maxCollatzLength));

		// If the calculated Collatz sequence length met the maximum
		// permitted Collatz sequence length and the integer is not one,
		// set the Collatz sequence length to negative one to indicate
		// that the integer's Collatz sequence length exceeds the
		// maximum permitted sequence length
		if ((collatzLength >= maxCollatzLength) &&
		    (intToEvaluate != 1))
		{
			collatzLength = -1;
		}

		return collatzLength;
	}

	static void putPairInDescendingFullArray(CollatzInfo pairToInsert,
						 CollatzInfo [] array)
	{
		// Precondition: The pair received by this method holds two
		// valid long integers, and the array received by this method is
		// sorted in descending order by pair key value 
		// Postcondition: The pair received by this method is inserted
		// into this method's received array in descending sort order by
		// key, then by pair value if that pair has a key greater than
		// or equal to the lowest key stored in this method's received
		// array. If the pair this method received has a key matching
		// the key of the last item in this function's received array,
		// this method's parameter pair is only inserted into this
		// method's parameter array if the parameter pair's pair value
		// is less than the pair value of the array's last item. The
		// last item of this method's parameter array is removed from
		// the array if this method's received parameter pair is added
		// to the array.

		// Retrieve the key of the pair to insert to determine where the
		// pair to insert should be placed within the pair array
		Long keyToInsert = pairToInsert.getKey();

		// Create a Boolean variable to flag whether to attempt
		// inserting the parameter pair into the array
		boolean addNewPair = false;

		// Check if the key to insert is greater than or equal to the
		// lowest key in the received array to determine whether to
		// insert the received parameter pair into the array
		int lastArrayIndex = arrayCapacity - 1;
		Long smallestArrayKey = array[lastArrayIndex].getKey();

		if (keyToInsert > smallestArrayKey)
		{
			addNewPair = true;
		}
		else if (keyToInsert == smallestArrayKey)
		{
			// Compare the pair values of the parameter pair and the
			// final array pair to determine whether to insert the
			// parameter pair into the array
			Long lastArrayPairValue = array[lastArrayIndex].getValue();

			if (pairValueToInsert < lastArrayPairValue)
			{
				addNewPair = true;
			}
			else if (pairValueToInsert >= lastArrayPairValue)
			{
				addNewPair = false;
			}
		}

		if (addNewPair)
		{
			// Code from GeeksforGeeks,
			// https://www.geeksforgeeks.org/search-insert-and-delete-in-a-sorted-array/
			// Accessed Wednesday, December 4th, 2019

			// Parse the array to determine where the parameter pair
			// should be added
			int currentArrayIndex;
			int firstArrayIndex = 0;

			for (currentArrayIndex = lastArrayIndex;
			     currentArrayIndex > firstArrayIndex;
			     currentArrayIndex--)
			{
				// Compare the key to insert to the next latest
				// unchecked array key to determine how to
				// rearrange the array contents
				int nextArrayIndex = currentArrayIndex - 1;
				Long nextKeyInArray = array[nextArrayIndex].getKey();

				if (keyToInsert > nextKeyInArray)
				{
					// Shift the array's contents to create
					// a space for the upcoming pair
					// insertion
					array[currentArrayIndex] = array[nextArrayIndex];
				}
				else if (keyToInsert < nextKeyInArray)
				{
					// Insert the parameter pair to place
					// the pair in the correct sorted
					// location in the array
					array[currentArrayIndex] = pairToInsert;

					// Leave the for loop to end the
					// insertion location search
					break;
				}
				else if (keyToInsert == nextKeyInArray)
				{
					// Compare the pair values of the pair
					// to insert and the next pair of the
					// array to determine where the
					// parameter pair should be placed in
					// the array
					Long pairValueToInsert = pairToInsert.getValue();
					Long nextPairValueInArray = array[nextArrayIndex].getValue();

					if (pairValueToInsert > nextPairValueInArray)
					{
						// Shift the array's contents to
						// create a space for the
						// upcoming pair insertion
						array[currentArrayIndex] = array[nextArrayIndex];
					}
					else if (pairValueToInsert < nextPairValueInArray)
					{
						// Insert the parameter pair to
						// place the pair in the correct
						// sorted location in the array
						array[currentArrayIndex] = pairToInsert;

						// Leave the for loop to end the
						// insertion location search
						break;
					}
					else if (pairValueToInsert == nextPairValueInArray)
					{
						// Stop attempting to place the
						// parameter pair in the array
						// to avoid storing a duplicate
						// pair in the array
						addNewPair = false;
						break;
					}
				}
			}

			// If the first array slot was reached in the array
			// parsing, insert the parameter pair at the beginning
			// of the array to place the pair in the correct sorted
			// position in the array
			if ((arrayIndex == firstindexOfArray) &&
			    (addNewPair))
			{
				array[firstArrayIndex] = pairToInsert;
			}
		}
	}

	// Code from GeeksforGeeks,
	// https://www.geeksforgeeks.org/search-insert-and-delete-in-a-sorted-array/
	// Accessed Saturday, November 30th, 2019
	static void putPairInDescendingArray (CollatzInfo pairToInsert,
					      CollatzInfo [] array,
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

		CollatzInfo [] collatzLengthArray = new CollatzInfo[collatzLengthsToStore];

		// Create a long variable to determine the maximum permitted
		// Collatz sequence length to store
		long maxCollatzLength = 5000000000L;

		// Create a long variable to designate the maximum integer to
		// receive a Collatz sequence length calculation
		long maxIntToEvaluate = Long.MAX_VALUE;

		// Calculate the Collatz sequence lengths of the positive
		// primitive integer range to determine the longest Collatz
		// sequence lengths
		storeCollatzInfo(collatzLengthsToStore,
				 maxIntToEvaluate,
				 maxCollatzLength);
	}
}
