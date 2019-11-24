/* Prgrammer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

#include <map>

using namespace std;

void storeCollatzInfo(long int maxCollatzLength);

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
	multimap<long int, int> collatzLengthMap;

	const long int maxCollatzLength = 5000000000;
	storeCollatzInfo(collatzLengthMap,
			 maxCollatzLength);
}

void storeCollatzInfo(multimap<long int, int> collatzLengthMap,
		      long int maxCollatzLength)
{
	// Precondition:
	// Postcondition:

	// Create lowes
	int lowestCollatzLength = -1;
	int highestCollatzLength = INT_MAX;
	
	for (int integer = 1; integer <= INT_MAX; integer++)
	{
		long int collatzLength = calculateCollatzLength(integer,
								maxCollatzLength);

		// 
		if (collatzLength != -1)
		{
			if (collatzLength > 
			collatzLengthMap.insert(pair<int, long int>(integer,
								    collatzLength));
		}
	}
}

int calculateCollatzLength(int integer,
			   long int maxCollatzLength)
{
	// Precondition: Both the received integer to be evaluated and the
	// received maximum Collatz sequence length were valid positive integers
	// Postcondition: The Collatz length calculated for the received integer
	// was returned to this function's caller if the length was less than or
	// equal to the maximum Collatz length parameter, or a negative one was
	// returned to this function's caller if the calculated Collatz length
	// exceeded the maximum Collatz length parameter

	long int collatzLength = 0;

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
