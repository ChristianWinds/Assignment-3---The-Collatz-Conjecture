/* Prgrammer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

#include <map>
#include <climits>

using namespace std;

void storeCollatzInfo(multimap<long int, int> collatzLengthMap,
		      int collatzLengthsToStore,
		      long int maxCollatzLength);
int calculateCollatzLength(int integer,
			   long int maxCollatzLength);
void eraseFirstMultimapItem(multimap<long int, int> multimapParameter);

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
	// A multimap is used to automatically sort the Collatz sequence lengths
	// in ascending order
	multimap<long int, int> collatzLengthMap;

	// Create an integer variable to determine the number of Collatz
	// sequence lengths to store
	const int collatzLengthsToStore = 10;

	const long int maxCollatzLength = 5000000000;

	// Calculate the Collatz sequence lengths of the positive primitive
	// integer range to determine the longest Collatz sequence lengths
	// within the specified quantity of Collatz sequence lengths to store
	storeCollatzInfo(collatzLengthMap,
			 collatzLengthsToStore,
			 maxCollatzLength);

	return 0;
}

void storeCollatzInfo(multimap<long int, int> collatzLengthMap,
		      int collatzLengthsToStore,
		      long int maxCollatzLength)
{
	// Precondition: The Collatz sequence length multimap is empty, and this
	// function's received quantity of Collatz sequence lengths to store and
	// maximum Collatz sequence length are valid positive integers
	// Postcondition: The Collatz sequence length multimap holds the
	// specified number of longest Collatz sequence lengths to store and
	// the lengths' respective integers

	// Create a multimap iterator to view the final intended item in the
	// multimap
	multimap <long int, int> :: iterator collatzMapIterator;

	// Evaluate integers from one to the maximum primitive integer value to
	// determine the longest Collatz sequence lengths possible for the
	// integers
	for (int integer = 1; integer <= INT_MAX; integer++)
	{
		long int collatzLength = calculateCollatzLength(integer,
								maxCollatzLength);

		// Check if the current integer's Collatz sequence length is
		// greater than zero to prevent storage of invalid Collatz
		// sequence lengths
		if (collatzLength > 0)
		{
			// Check the number of elements in the Collatz Length
			// multimap and the to keep the specified number of 
			// longest Collatz sequence length and integer pairs
			if (collatzLengthMap.size() < collatzLengthsToStore)
			{
				collatzLengthMap.insert(pair<long int, int>(integer,
									    collatzLength));
			}
			else if (collatzLength > collatzMapIterator -> first)
			{
				// Insert the new Collatz sequence length and
				// integer pair to update the longest Collatz
				// sequence lengths within the specified number
				// of stored Collatz sequence lengths
				collatzLengthMap.insert(pair<long int, int>(integer,
									    collatzLength));

				// Erase the lowest Collatz sequence length from
				// the Collatz sequence length multimap to limit
				// the number of stored Collatz sequence lengths
				// to the specified length storage quantity
				eraseFirstMultimapItem(collatzLengthMap);
			}
		}
	}
}

int calculateCollatzLength(int integer,
			   long int maxCollatzLength)
{
	// Precondition: Both the received integer to be evaluated and the
	// received maximum Collatz sequence length were valid positive integers
	// Postcondition: The Collatz sequence length calculated for the
	// received integer was returned to this function's caller if the length
	// was less than or equal to the maximum Collatz sequence length
	// parameter, or a negative one was returned to this function's caller
	// if the calculated Collatz sequence length exceeded the maximum
	// Collatz sequence length parameter

	long int collatzLength = 0;

	// Perform the Collatz Conjecture calculations upon the received integer
	// until either the integer equals a value of one, or the Collatz
	// sequence length exceeds the maximum permitted Collatz sequence length
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

	// If the calculated Collatz sequence length met the maximum permitted
	// Collatz sequence length and the integer is not one, set the Collatz
	// sequence length to negative one to indicate that the integer's
	// Collatz sequence length exceeds the maximum permitted
	if ((collatzLength >= maxCollatzLength) &&
	    (integer != 1))
	{
		collatzLength = -1;
	}

	return collatzLength;
}

void eraseFirstMultimapItem(multimap<long int, int> multimapParameter)
{
	// Precondition: The received multimap holds at least one item
	// Postcondition: The multimap's first item was erased

	// Create an iterator to select the first multimap item for erasure
	multimap<long int, int> :: iterator firstItem = multimapParameter;

	multimapParameter.erase(firstItem);
}
