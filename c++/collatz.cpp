/* Prgrammer: Christian Winds
 * Course: CSC 330 Organization of Programming Languages
 * School Year: 2019-2020 School Year */

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <climits>

using namespace std;

void storeCollatzInfo(multimap<long int, int> &collatzLengthMap,
		      int collatzLengthsToStore,
		      long int maxCollatzLength,
		      int maxIntToEvaluate);
int calculateCollatzLength(int integer,
			   long int maxCollatzLength);
void printByCollatzLengths(multimap<long int, int> collatzLengthMap);
void printByCollatzSequenceIntegers(multimap<long int, int> collatzLengthMap,
				    long int maxCollatzLength)
void eraseFirstMultimapItem(multimap<long int, int> &multimapParameter);
void printMultimapSortedByKeyValue(multimap<long int, int> multimapParameter,
				   int leftColumnWidth);
void printMultimapSortedByMappedValue(multimap<long int, int> originalMultimap);
void sortByMappedValue(multimap<long int, int> originalMultimap,
		       multimap<int, long int> &mappedValueSortedMap);
void printTwoColumnHeader(const string leftColumnName,
			  const string rightColumnName,
			  const string separator,
			  int leftColumnWidth);
void printTwoColumnIntegers(const long int leftInt,
			    const long int rightInt,
			    int leftColumnWidth);
string intToString(long int originalInt);

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

	// Create an integer constant to designate the maximum integer to
	// receive a Collatz sequence length calculation
	const int maxIntToEvaluate = 10;

	// Calculate the Collatz sequence lengths of the positive primitive
	// integer range to determine the longest Collatz sequence lengths
	// within the specified quantity of Collatz sequence lengths to store
	storeCollatzInfo(collatzLengthMap,
			 collatzLengthsToStore,
			 maxCollatzLength,
			 maxIntToEvaluate);

	printByCollatzLengths(collatzLengthMap);

	// Print a blank line to separate the two printed Collatz sequence
	// information printouts
	cout << endl;

	printByCollatzSequenceIntegers(collatzLengthMap,
				       maxCollatzLength);

	return 0;
}

void storeCollatzInfo(multimap<long int, int> &collatzLengthMap,
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
				collatzLengthMap.insert(pair<long int, int>(collatzLength,
									    intToEvaluate));
			}
			else if (collatzLength > collatzMapIterator -> first)
			{
				// Insert the new Collatz sequence length and
				// integer pair to update the longest Collatz
				// sequence lengths within the specified number
				// of stored Collatz sequence lengths
				collatzLengthMap.insert(pair<long int, int>(collatzLength,
									    intToEvaluate));

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
	do
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
	} while ((integer != 1) &&
		 (collatzLength < maxCollatzLength));

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

	const string leftColumnName = "Collatz Sequence Length";
	const string rightColumnName = "Integer";
	const string headerSeparator = " | ";

	// Calculate the left output column's width to separate the printed
	// Collatz sequence length and integer values
	int leftColumnWidth = leftColumnName.length() + headerSeparator.length();

	// Print a header to label the Collatz sequence length and evaluated
	// integer columns
	printTwoColumnHeader(leftColumnName,
			     rightColumnName,
			     headerSeparator,
			     leftColumnWidth);

	printMultimapSortedByKeyValue(collatzLengthMap,
				      leftColumnWidth);
}

void printByCollatzSequenceIntegers(multimap<long int, int> collatzLengthMap,
				    long int maxCollatzLength)
{
	// Precondition: The Collatz sequence length multimap received by this
	// function holds at least one Collatz sequence length and integer pair
	// Postcondition: The Collatz sequence length and integer pairs in this
	// function's received Collatz sequence length map are printed to the
	// screen in ascending order sorted primarily by integer magnitude, then
	// secondarily by Collatz sequence length

	const string leftColumnName = "Integer";
	const string rightColumnName = "Collatz Sequence Length";
	const string separator = " | ";

	// Calculate the maximum Collatz sequence length's string size to
	// prepare to determine the left printed column's width
	int maxCollatzLengthStringSize = intToString(maxCollatzLength).size;

	// Set the left printed column width to include both the left column
	// name and the left column's longest possible integer string size in
	// the left column
	int leftColumnWidth = max(leftColumnName.size(),
				  maxCollatzLengthString.size);

	// Print a header to label the evaluated integer and Collatz sequence
	// length columns
	printTwoColumnHeader(leftColumnName,
			     rightColumnName,
			     separator,
			     leftColumnWidth);

	printMultimapSortedByMappedValue(collatzLengthMap);
}

void eraseFirstMultimapItem(multimap<long int, int> &multimapParameter)
{
	// Precondition: The received multimap holds at least one item
	// Postcondition: The multimap's first item was erased

	// Create an iterator to select the first multimap item for erasure
	multimap<long int, int> :: iterator firstItem = multimapParameter.begin();

	multimapParameter.erase(firstItem);
}

void printMultimapSortedByKeyValue(multimap<long int, int> multimapParameter,
				   int leftColumnWidth)
{
	// Precondition: The multimap this function receives holds at least one
	// valid item, this function's received separator string is a valid
	// string, and this function's received left column width is a valid
	// positive integer
	// Postcondition: The items of the multimap are printed onto the screen
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
		printTwoColumnIntegers((*printIterator).first,
				       (*printIterator).second,
				       leftColumnWidth);
	}
}

void printMultimapSortedByMappedValue(multimap<long int, int> originalMultimap)
{
	// Precondition: The multimap this function receives holds at least one
	// valid item
	// Postcondition: The items from the multimap received by this function
	// are printed onto the screen in ascending sorted order by mapped value

	// Create a mapped value-sorted duplicate multimap by re-sorting this
	// function's received multimap parameter's contents in mapped value
	// order
	multimap<int, long int> mappedValueSortedMap;
	sortByMappedValue(originalMultimap,
			  mappedValueSortedMap);

	// Code from cplusplus.com,
	// http://www.cplusplus.com/reference/map/multimap/erase/
	// Accessed Monday, November 25th, 2019
	// Create an iterator to parse the mapped value-sorted multimap's
	// contents for printing
	multimap<int, long int> :: iterator printIterator;

	// Use a for loop to access and print each of the mapped value-sorted
	// multimap's items
	for (printIterator = mappedValueSortedMap.begin();
	     printIterator != mappedValueSortedMap.end();
	     printIterator++)
	{
		cout << (*printIterator).first << "\t" <<
			(*printIterator).second << endl;
	}
}

void sortByMappedValue(multimap<long int, int> originalMultimap,
		       multimap<int, long int> &mappedValueSortedMap)
{
	// Precondition: The "original multimap" multimap this function receives
	// holds at least one valid item, and the "mapped value-sorted map"
	// multimap this function receives is empty
	// Postcondition: The "mapped value sorted multimap" received by this
	// function holds the "original multimap" map contents stored in
	// ascending order of the "original multimap" mapped values

	// Code from cplusplus.com,
	// http://www.cplusplus.com/reference/map/multimap/erase/
	// Accessed Monday, November 25th, 2019
	// Create an iterator to parse the original parameter multimap's
	// contents
	multimap<long int, int> :: iterator originalMapIterator;

	// Parse the original parameter multimap's contents to transfer those
	// contents to the mapped value-sorted multimap by mapped value
	// order
	for (originalMapIterator = originalMultimap.begin();
	     originalMapIterator != originalMultimap.end();
	     originalMapIterator++)
	{
		// Insert the original multimap's pairs' contents into the
		// mapped value-sorted map by the original multimap's mapped
		// values as keys to re-sort the original multimap's contents by
		// the contents' original mapped values within the mapped
		// value-sorted map
		mappedValueSortedMap.insert(pair<int, long int> ((*originalMapIterator).second, (*originalMapIterator).first));
	}
}

void printTwoColumnHeader(const string leftColumnName,
			  const string rightColumnName,
			  const string separator,
			  int leftColumnWidth)
{
	// Precondition: This function's received left column name, right column
	// name, and separator strings are valid strings, the column name
	// strings are non-empty strings, and this function's received left
	// column width is a valid non-negative integer
	// Postcondition: A header line in order of this function's received
	// left column name, separator, and right column name is printed to the
	// screen with the specified left column width 

	// Code from C++ Patterns, 
	// https://cpppatterns.com/patterns/write-data-in-columns.html
	// Accessed Monday, November 25th, 2019
	// Combine the left column name and separator into one column to
	// properly space the printed header
	cout << left << setw(leftColumnWidth) << (leftColumnName + separator);

	cout << rightColumnName << endl;
}

void printTwoColumnIntegers(const long int leftInt,
			    const long int rightInt,
			    int leftColumnWidth)
{
	// Precondition: This function's received left integer and right
	// integer are valid integers, and this function's received left column
	// width is a valid non-negative integer
	// Postcondition: A header line with this function's received left
	// integer and right integer is printed to the screen with the specified
	// left column width 

	// Code from C++ Patterns, 
	// https://cpppatterns.com/patterns/write-data-in-columns.html
	// Accessed Monday, November 25th, 2019
	// Use the specified left column width to separate the left and right integers
	cout << left << setw(leftColumnWidth) << leftInt << rightInt << endl;
}

string intToString(long int originalInt)
{
	// Precondition: The integer this function received is a valid integer
	// Postcondition: This function returns a string of this function's
	// received parameter integer to this function's caller

	// Code from cplusplus.com,
	// http://www.cplusplus.com/articles/D9j2Nwbp/
	// Accessed Monday, November 25th, 2019
	// Create an output string stream to convert this function's original
	// integer parameter to a string
	ostringstream convert;

	// Place the original integer parameter's content into the output string
	// stream to convert the integer parameter's content into string
	// characters
	convert << originalInt;

	// Place the output string stream's content into a "string integer"
	// variable to store the string stream's content as a string
	string stringInteger = convert.str();

	return stringInteger;
}
