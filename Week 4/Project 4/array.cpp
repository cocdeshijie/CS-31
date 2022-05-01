#include <iostream>
#include <string>
#include <cassert>

using namespace std;


int locateMaximum(const string array[], int n)
{
	// -1 if n <= 0
	if (n <= 0)
	{
		return -1;
	}
	// loop through and compoare to find the largest index
	int largestIndex = 0;
	for (int i = 1; i < n; i++)
	{
		if (array[largestIndex] < array[i])
		{
			largestIndex = i;
		}
	}
	return largestIndex;
}

bool hasDuplicatedValues(const string array[], int n)
{
	//  if n <= 0 return false
	if (n <= 0)
	{
		return false;
	}
	// loop through two times and if two different index have same value return true
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[i] == array[j] && !(i == j))
			{
				return true;
			}
		}
	}
	// return false otherwise
	return false;
}

int countAllVowels(const string array[], int n)
{
	// if n <= 0 return -1
	if (n <= 0)
	{
		return -1;
	}

	string vowels = "aeiouyAEIOUY";
	int vowelsCount = 0;
	//loop through each item and their character, add to vowelsCount if found vowel
	for (int i = 0; i < n; i++)
	{
		int itemLength = array[i].length();
		for (int itemIndex = 0; itemIndex < itemLength; itemIndex++)
		{
			if (vowels.find(array[i][itemIndex]) != string::npos)
			{
				vowelsCount++;
			}

		}
	}
	return vowelsCount;
}

int moveToEnd(string array[], int n, int position)
{
	//  if n <= 0 or position is < 0 or position >= n, return -1
	if (n <= 0 || position < 0 || position >= n)
	{
		return -1;
	}
	string endString = array[n-1];
	string positionString = array[position];
	array[n-1] = positionString;
	array[position] = endString;
	return position;
}

int countIntegers(const string array[], int n)
{
	// if n <= 0 return -1
	if (n <= 0)
	{
		return -1;
	}

	string numbers = "0123456789";
	int integers = 0;
	// loop through each item and if an item is made up with only "1234567890" then add to integer count
	for (int i = 0; i < n; i++)
	{
		if (array[i].find_first_not_of("0123456789") == string::npos)
		{
			integers++;
		}
	}
	return integers;
}

int rotateRight(string array[], int n, int amount)
{
	// if  n <= 0 or amount < 0, return -1
	if (n <= 0 || amount < 0)
	{
		return -1;
	}
	// rotate right amount of times
	for (int rotate = 0; rotate < amount; rotate++)
	{
		string temp = array[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			array[i] = array[i - 1];
		}
		array[0] = temp;
	}
	// return element count rotated
	return (n * amount);
}

int shiftLeft(string array[], int n, int amount, string placeholder)
{
	// if n <= 0 or amount < 0, return -1
	if (n <= 0 || amount < 0)
	{
		return -1;
	}
	// rotate left 
	for (int rotate = 0; rotate < amount; rotate++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			array[i] = array[i + 1];
		}
	}
	
	// use placeholder amount of times
	if (amount <= n)
	{
		for (int i = 0; i < amount; i++)
		{
			array[n - 1 - i] = placeholder;
		}
	}
	if (amount > n)
	{
		for (int i = 0; i < n; i++)
		{
			array[n - 1 - i] = placeholder;
		}
	}
	// the amount of times placeholder used cannot be larger than the size of the the array
	if (amount > n)
	{
		return n;
	}
	return amount;
}

int main()
{
	string one[1] = { "test" };
	string two[5] = { "one", "two", "three", "four", "five" };
	string three[8] = { "one", "one", "two", "three", "four", "five", "six", "seven" };
	string four[5] = { "123", "379834574985739084", "3242342 2342", "231231.1231", "123123/" };


	assert(locateMaximum(one, 1) == 0);
	assert(locateMaximum(two, 3) == 1);
	assert(locateMaximum(three, 5) == 2);
	assert(locateMaximum(one, 0) == -1);

	assert(hasDuplicatedValues(one, 1) == false);
	assert(hasDuplicatedValues(two, 5) == false);
	assert(hasDuplicatedValues(three, 3) == true);
	assert(hasDuplicatedValues(one, 0) == false);

	assert(countAllVowels(one, 0) == -1);
	assert(countAllVowels(one, 1) == 1);
	assert(countAllVowels(two, 5) == 9);
	assert(countAllVowels(two, 2) == 3);
	assert(countAllVowels(three, 8) == 14);

	assert(moveToEnd(one, 1, 0) == 0);
	assert(moveToEnd(two, 3, 0) == 0);
	assert(two[0] == "three" && two[2] == "one");
	assert(moveToEnd(three, 7, 2) == 2);
	assert(three[2] == "six" && three[6] == "two");
	assert(moveToEnd(three, 2, 2) == -1);
	assert(moveToEnd(three, 1, 2) == -1);

	assert(countIntegers(four, 5) == 2);
	assert(countIntegers(four, 1) == 1);
	assert(countIntegers(four, 0) == -1);


	string oneone[1] = { "test" };
	string twotwo[5] = { "one", "two", "three", "four", "five" };
	string threethree[8] = { "one", "one", "two", "three", "four", "five", "six", "seven" };
	string fourfour[5] = { "123", "379834574985739084", "3242342 2342", "231231.1231", "123123/" };

	assert(rotateRight(oneone, 1, 1000) == 1000);
	assert(oneone[0] == "test");
	assert(rotateRight(twotwo, 3, 2) == 6);
	assert(twotwo[0] == "two" && twotwo[1] == "three" && twotwo[2] == "one");

	assert(shiftLeft(threethree, 5, 2, "test") == 2);
	assert(threethree[0] == "two" && threethree[1] == "three" && threethree[2] == "four" && threethree[3] == "test" && threethree[4] == "test");
	assert(shiftLeft(fourfour, 5, 10, "test") == 5);
	assert(fourfour[0] == "test" && fourfour[1] == "test"&& fourfour[2] == "test"&& fourfour[3] == "test"&& fourfour[4] == "test");


	cerr << "success!" << endl;
	return 0;
}