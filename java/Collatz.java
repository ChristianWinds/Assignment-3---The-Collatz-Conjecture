/* Programmer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

public class Collatz
{
	static void storeCollatzInfo()
	{
		// Precondition:
		// Postcondition:

		for (int integer = 1;
		     integer <= maxIntToEvaluate;
		     integer++)
		{
			// End the Collatz sequence length calculations if the
			// maximum specified integer of the integer calculation
			// range was met to avoid an error
			if (integer >= maxIntToEvaluate)
			{
				break;
			}
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
