/* Programmer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */
public class CollatzInfo
{
	long collatzLength;
	long integer;

	public CollatzInfo(long collatzLength,
			   long integer)
	{
		// Precondition: This method's received Collatz sequence length
		// and Collatz sequence integer long integers are valid positive
		// long integers
		// Postcondition: The Collatz info object holds this method's
		// received Collatz sequence length and Collatz sequence integer
		// long integers
		collatzLength = this.collatzLength;
		integer = this.integer;
	}
}
