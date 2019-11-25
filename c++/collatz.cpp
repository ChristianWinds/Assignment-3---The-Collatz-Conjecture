/* Prgrammer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

#include <iostream>
#include <string>
#include <map>
#include <climits>

using namespace std;

void storeCollatzInfo(multimap<long int, int> collatzLengthMap,
		      int collatzLengthsToStore,
		      long int maxCollatzLength,
		      int maxIntToEvaluate);
int calculateCollatzLength(int integer,
			   long int maxCollatzLength);
void eraseFirstMultimapItem(multimap<long int, int> multimapParameter);
void printMultimapSortedByKeyValue(multimap<long int, int> multimapParameter);

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

	// Create an integer constant to designate the maximum integer to receive
	// a Collatz sequence length calculation
	const int maxIntToEvaluate = INT_MAX;

	// Calculate the Collatz sequence lengths of the positive primitive
	// integer range to determine the longest Collatz sequence lengths
	// within the specified quantity of Collatz sequence lengths to store
	storeCollatzInfo(collatzLengthMap,
			 collatzLengthsToStore,
			 maxCollatzLength,
			 maxIntToEvaluate);

	printByCollatzLengths(collatzLengthMap);

	return 0;
}

void storeCollatzInfo(multimap<long int, int> collatzLengthMap,
		      int collatzLengthsToStore,
		      long int maxCollatzLength,
		      int maxIntToEvaluate)
{
	// Precondition: The Collatz sequence length multimap is empty, and this
	// function's received quantity of Collatz sequence lengths to store,
	// the maximum Collatz sequence length, and the maximum integer to
	// evaluate are valid positive integers
	// Postcondition: The Collatz sequence length multimap holds the
	// specified number of longest Collatz sequence lengths to store and
	// the lengths' respective integers

	// Create a multimap iterator to view the final intended item in the
	// multimap
	multimap <long int, int> :: iterator collatzMapIterator;

	// Evaluate integers from one to the maximum primitive integer value to
	// determine the longest Collatz sequence lengths possible for the
	// integers
	for (int intToEvaluate = 1;
	     intToEvaluate <= maxIntToEvaluate;
	     intToEvaluate++)
	{
		long int collatzLength = calculateCollatzLength(intToEvaluate,
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
				collatzLengthMap.insert(pair<long int, int>(intToEvaluate,
									    collatzLength));
			}
			else if (collatzLength > collatzMapIterator -> first)
			{
				// Insert the new Collatz sequence length and
				// integer pair to update the longest Collatz
				// sequence lengths within the specified number
				// of stored Collatz sequence lengths
				collatzLengthMap.insert(pair<long int, int>(intToEvaluate,
									    collatzLength));

				// Erase the lowest Collatz sequence length from
				// the Collatz sequence length multimap to limit
				// the number of stored Collatz sequence lengths
				// to the specified length storage quantity
				eraseFirstMultimapItem(collatzLengthMap);
			}
		}

		// End the Collatz sequence length calculations if the maximum
		// specified integer of the integer calculation range was met
		// to avoid an error
		if (intToEvaluate >= maxIntToEvaluate)
		{
			break;
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

void printByCollatzLengths(multimap<long int, int> collatzLengthMap)
{
	// Precondition: The Collatz sequence length multimap received by this
	// function holds at least one Collatz sequence length and integer pair
	// Postcondition: The Collatz sequence length and integer pairs in this
	// function's received Collatz sequence length map are printed to the
	// screen in ascending order sorted primarily by Collatz sequence
	// length, then secondarily by integer magnitude when two or more
	// Collatz sequence lengths match

	
}

void eraseFirstMultimapItem(multimap<long int, int> multimapParameter)
{
	// Precondition: The received multimap holds at least one item
	// Postcondition: The multimap's first item was erased

	// Create an iterator to select the first multimap item for erasure
	multimap<long int, int> :: iterator firstItem = multimapParameter.begin();

	multimapParameter.erase(firstItem);
}

void printMultimapSortedByKeyValue(multimap<long int, int> multimapParameter)
{
	// Precondition: The multimap this function receives holds at least one
	// valid item
	// Postondition: The items of the multimap are printed onto the screen
	// in ascending sorted order by key value

	// Code from cplusplus.com,
	// http://www.cplusplus.com/reference/map/multimap/erase/
	// Accessed Monday, November 25th, 2019
	// Create an iterator to parse the multimap's contents for printing
	multimap<long int, int> :: iterator printIterator;

	// Use a for loop to access and print each of the multimap's items
	for (printIterator = multimapParameter.begin();
	     printIterator != multimapParameter.end();
	     printIterator++)
	{
		cout << (*printIterator).first << "\t" <<
			(*printIterator).second << endl;
	}
}
