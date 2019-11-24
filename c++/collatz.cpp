/* Prgrammer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

using namespace std;

void storeCollatzInfo();

// This program employs a "CollatzInfo" class type to pair integers with the
// integers' respective Collatz sequence lengths
class CollatzInfo
{
	public:

	int integer;

	// Create an integer variable to store an integer's Collatz sequence
	// length
	int collatzLength;
};

int main()
{

	const int maxCollatzLength = 5000000000;
	storeCollatzInfo(maxCollatzLength);
}

void storeCollatzInfo(int maxCollatzLength)
{
	// Precondition:
	// Postcondition:

	

	for (int integer = 1; integer <= INT_MAX; integer++)
	{
		calculateCollatzLength(integer, maxCollatzLength);
	}
}

int calculateCollatzLength(int integer, int maxCollatzLength)
{
	// Precondition: Both the received integer to be evaluated and the
	// received maximum Collatz sequence length were valid positive integers
	// Postcondition: The Collatz length calculated for the received integer
	// was returned to this function's caller if the length was less than or
	// equal to the maximum Collatz length parameter, or a negative one was
	// returned to this function's caller if the calculated Collatz length
	// exceeded the maximum Collatz length parameter

	int collatzLength = 0;

	while ((integer != 1) &&
	       (collatzLength < maxCollatzLength))
	{
		// Check whether the integer is even or odd to determine which
		// Collatz Conjecture operations should be performed
		if (integer % 2 == 0)
		{
			integer = integer / 2;
		}
		else
		{
			integer = (integer * 3) + 1;
		}

		collatzLength++;
	}

	return collatzLength;
}
