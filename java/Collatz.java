/* Programmer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

public class Collatz
{
	static void storeCollatzInfo(int collatzLengthsToStore,
				     long maxIntToEvaluate,
				     long maxCollatzLength,
				     CollatzInfo [] collatzLengthArray)
	{
		// Precondition: The reeived integer of Collatz sequence lengths
		// to store and the long integers of the maximum integer to
		// evaluate and maximum Collatz sequence length are valid
		// positive integers, and the received Collatz sequence length
		// array is empty
		// Postcondition: The received Collatz sequence length array is
		// filled with the specified quantity of Collatz sequence
		// lengths sorted in descending order

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
								 arrayQuantity,
								 collatzLengthsToStore);
					arrayQuantity++;
				}
				else
				{
					putPairInDescendingFullArray(collatzPair,
								     collatzLengthArray,
								     collatzLengthsToStore);
				}
			}

			// End the Collatz sequence length calculations if the
			// maximum specified integer of the integer calculation
			// range was met to avoid an error
			if (intToEvaluate >= maxIntToEvaluate)
			{
				break;
			}
		}
	}

	static long calculateCollatzLength(long intToEvaluate,
					   long maxCollatzLength)
	{
		// Precondition: The integer to evaluate and maximum Collatz
		// sequence length received by this method are valid long
		// integers
		// Postcondition: This method delivered the evaluated integer's
		// Collatz sequence length to this method's caller if the
		// sequence length is less than or equal to the maximum
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
						 CollatzInfo [] array,
						 int arrayCapacity)
	{
		// Precondition: The Collatz info object received by this method
		// holds two valid long integers, and the array received by this
		// method is sorted in descending order primarily by Collatz
		// sequence length, and secondarily by Collatz sequence integer
		// Postcondition: The Collatz info object received by this
		// method is inserted into this method's received array in
		// descending sort order by Collatz sequence length, then by
		// Collatz sequence integer if that Collatz info object has a
		// Collatz sequence length greater than or equal to the lowest
		// Collatz sequence length stored in this method's received
		// array. If the Collatz info object this method received has a
		// Collatz sequence length matching the Collatz sequence length
		// of the last item in this function's received array, this
		// method's parameter Collatz info object is only inserted into
		// this method's parameter array if the parameter Collatz info
		// object's Collatz sequence integer value is less than the
		// Collatz sequence integer value of the array's last item. The
		// last item of this method's parameter array is removed from
		// the array if this method's received parameter Collatz info
		// object is added to the array.

		// Retrieve the Collatz sequence length of the Collatz info
		// object to insert to determine where the Collatz info object
		// to insert should be placed within the Collatz length array
		long lengthToInsert = pairToInsert.collatzLength;

		// Create a Boolean variable to flag whether to attempt
		// inserting the parameter Collatz info object into the array
		boolean addNewPair = false;

		// Check if the Collatz sequence length to insert is greater
		// than or equal to the lowest Collatz sequence length in the
		// received array to determine whether to insert the received
		// parameter Collatz info object into the array
		int lastArrayIndex = arrayCapacity - 1;
		Long smallestArrayCollatzLength = array[lastArrayIndex].collatzLength;

		if (lengthToInsert > smallestArrayCollatzLength)
		{
			addNewPair = true;
		}
		else if (lengthToInsert == smallestArrayCollatzLength)
		{
			// Compare the Collatz sequence integers of the
			// parameter Collatz info object and the final array
			// Collatz info object to determine whether to insert the
			// parameter Collatz info object into the array
			long lastArrayIntegerValue = array[lastArrayIndex].integer;
			long integerToInsert = pairToInsert.integer;

			if (integerToInsert < lastArrayIntegerValue)
			{
				addNewPair = true;
			}
			else if (integerToInsert >= lastArrayIntegerValue)
			{
				addNewPair = false;
			}
		}

		if (addNewPair)
		{
			// Code from GeeksforGeeks,
			// https://www.geeksforgeeks.org/search-insert-and-delete-in-a-sorted-array/
			// Accessed Wednesday, December 4th, 2019

			// Parse the array to determine where the parameter
			// Collatz info object should be added
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
				long nextCollatzLengthInArray = array[nextArrayIndex].collatzLength;

				if (lengthToInsert > nextCollatzLengthInArray)
				{
					// Shift the array's contents to create
					// a space for the upcoming Collatz info object
					// insertion
					array[currentArrayIndex] = array[nextArrayIndex];
				}
				else if (lengthToInsert < nextCollatzLengthInArray)
				{
					// Insert the parameter Collatz info
					// object to place the Collatz info
					// object in the correct sorted location
					// in the array
					array[currentArrayIndex] = pairToInsert;

					// Leave the for loop to end the
					// insertion location search
					break;
				}
				else if (lengthToInsert == nextCollatzLengthInArray)
				{
					// Compare the pair values of the pair
					// to insert and the next pair of the
					// array to determine where the
					// parameter pair should be placed in
					// the array
					Long integerToInsert = pairToInsert.integer;
					Long nextIntegerInArray = array[nextArrayIndex].integer;

					if (integerToInsert > nextIntegerInArray)
					{
						// Shift the array's contents to
						// create a space for the
						// upcoming pair insertion
						array[currentArrayIndex] = array[nextArrayIndex];
					}
					else if (integerToInsert < nextIntegerInArray)
					{
						// Insert the parameter pair to
						// place the pair in the correct
						// sorted location in the array
						array[currentArrayIndex] = pairToInsert;

						// Leave the for loop to end the
						// insertion location search
						break;
					}
					else if (integerToInsert == nextIntegerInArray)
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
			int firstIndexOfArray = 0;
			if ((currentArrayIndex == firstIndexOfArray) &&
			    (addNewPair))
			{
				array[firstArrayIndex] = pairToInsert;
			}
		}
	}

	// Code from GeeksforGeeks,
	// https://www.geeksforgeeks.org/search-insert-and-delete-in-a-sorted-array/
	// Accessed Saturday, November 30th, 2019
	static void putPairInDescendingArray(CollatzInfo pairToInsert,
					     CollatzInfo [] array,
					     int pairsInArray,
					     int arrayCapacity)
	{
		// Precondition: The array this method receives holds at least
		// one unused slot, that array is sorted in descending order
		// primarily by Collatz sequence length and secondarily by
		// Collatz sequence integer value, this method's received
		// quantity of Collatz info objects within the received array is
		// a valid non-negative integer, and the Collatz info object to
		// insert received by this method holds two valid long type values
		// Postcondition: The Collatz info object received by this
		// function is inserted into this function's received array if
		// the object does not have a duplicate in the array.

		// Retrieve the key of the pair to insert to determine where the
		// pair to insert should be placed within the pair array
		long lengthToInsert = pairToInsert.collatzLength;

		int arrayIndex;

		for (arrayIndex = pairsInArray - 1;
		     (arrayIndex >= 0 && array[arrayIndex].collatzLength < lengthToInsert);
		     arrayIndex--)
		{
			// Shift the contents within the array to open a slot to
			// place the pair to insert within the array in
			// descending sorted order
			array[arrayIndex + 1] = array[arrayIndex];
		}

		array[arrayIndex + 1] = pairToInsert;
	}

	public static void main(String args[])
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
				 maxCollatzLength,
				 collatzLengthArray);
	}
}
