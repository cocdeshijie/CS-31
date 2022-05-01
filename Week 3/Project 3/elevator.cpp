#include <cassert>
#include <iostream>
#include <string>
using namespace std;

// Helpful Code For Project 3
int extractNumber(string s, size_t& index)
{
	// track the integer value found
	int quantity(0);
	bool foundADigit = false;

	while (index < s.size())
	{
		char c = s.at(index);
		// we are only interested in digit characters 0-9
		if (c >= '0' && c <= '9')
		{
			foundADigit = true;
			// extract one digit and add it to the cumulative 
			// value held in quantity
			int digit = c - '0';
			quantity = quantity * 10 + digit;
			index = index + 1;
		}
		else
		{
			break;
		}
	}
	if (!foundADigit)
	{
		quantity = -1;
	}
	return(quantity);
}

bool isValidElevatorString(string elevatorstring)
{
	// elevator start with 0 passenger, used to check if it ever goes below 0
	int passenger = 0;
	// elevator start with door closed
	bool doorclosed = true;
	// "the only characters present should be M, O, C, +, - and digit characters"
	if (elevatorstring.find_first_not_of("MOC+-1234567890") != string::npos)
	{
		return false;
	}
	//  Require M and digits for an elevator string to be valid
	if (elevatorstring[0] != 'M')
	{
		return false;
	}
	// "elevator strings must end with either O, C or a digit character and not a + , -or M"
	// M, O, C, +, - and digit characters has already been checked so only need to make sure it doesnt end in +, -, or M
	if (elevatorstring.back() == '+' || elevatorstring.back() == '-' || elevatorstring.back() == 'M')
	{
		return false;
	}
	// loop through every character in string to check more
	for (int index = 0; index < elevatorstring.length(); index++)
	{	
		// floor related 
		if (elevatorstring[index] == 'M')
		{
			// door need to be closed for elevator to move
			if (!doorclosed)
			{
				return false;
			}
			// "only above ground floors" and "an elevator string must begin with M followed by digits"
			// checks if the character after M is a number
			if (!isdigit(elevatorstring[index + 1]))
			{
				return false;
			}
		}
		// get string after current O
		string remainingstring = elevatorstring.substr(index + 1);
		// "once doors are open, doors cannot be opened again"
		// find O
		if (elevatorstring[index] == 'O')
		{
			// if there is more O after the current O
			for (int remainingstringindex = 0; remainingstringindex < remainingstring.length(); remainingstringindex++)
			{
				if (remainingstring[remainingstringindex] == 'O')
				{
					// check if there is C in between
					string characterinbewteen = remainingstring.substr(0, remainingstringindex);
					if (!(characterinbewteen.find("C") != string::npos))
					{
						return false;
					}
				}
			}
			doorclosed = false;
		}
		// "elevator doors can only be closed if they are currently open"
		// find C
		if (elevatorstring[index] == 'C')
		{
			//check if there is any O before current C since elevator start with door closed
			string beforestring = elevatorstring.substr(0, index);
			if (!(beforestring.find("O") != string::npos))
			{
				return false;
			}
			// if there is more O after the current O
			for (int remainingstringindex = 0; remainingstringindex < remainingstring.length(); remainingstringindex++)
			{
				if (remainingstring[remainingstringindex] == 'C')
				{
					// check if there is O in between
					string characterinbewteen = remainingstring.substr(0, remainingstringindex);
					if (!(characterinbewteen.find("O") != string::npos))
					{
						return false;
					}
				}
			}
			doorclosed = true;
		}
		// "passenger count cannot go negative as the elevator string is processed"
		if (elevatorstring[index] == '+')
		{
			// passenger cannot get on with door closed
			if (doorclosed)
			{
				return false;
			}
			// add
			size_t numberindex = index + 1;
			passenger = passenger + extractNumber(elevatorstring, numberindex);
		}
		if (elevatorstring[index] == '-')
		{
			// passenger cannot get off with door closed
			if (doorclosed)
			{
				return false;
			}
			// subtract and find if passenger count go negative
			size_t numberindex = index + 1;
			passenger = passenger - extractNumber(elevatorstring, numberindex);
			if (passenger < 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool doorsOpen(string elevatorstring)
{
	// elevator start with door closed
	bool doorclosed = true;
	// parameter need to be a well-formed elevator string
	if (!isValidElevatorString(elevatorstring)) {
		return false;
	}
	// loop
	for (int index = 0; index < elevatorstring.length(); index++)
	{
		// open and close
		if (elevatorstring[index] == 'O')
		{
			doorclosed = false;
		}
		if (elevatorstring[index] == 'C')
		{
			doorclosed = true;
		}
	}
	// return true if door is not closed at end
	if (!doorclosed)
	{
		return true;
	}
	// return false otherwise
	return false;
}

int endingPassengers(string elevatorstring)
{
	// passenger start with 0
	int passenger = 0;
	// if not valid return -1
	if (!isValidElevatorString(elevatorstring)) {
		return -1;
	}
	for (int index = 0; index < elevatorstring.length(); index++)
	{
		if (elevatorstring[index] == '+')
		{
			// add
			size_t numberindex = index + 1;
			passenger = passenger + extractNumber(elevatorstring, numberindex);
		}
		if (elevatorstring[index] == '-')
		{
			// subtract and find if passenger count go negative
			size_t numberindex = index + 1;
			passenger = passenger - extractNumber(elevatorstring, numberindex);
		}
	}
	return passenger;
}

// same as endingPassengers but find the largest int through the loop
int mostPassengers(string elevatorstring)
{
	// passenger start with 0
	int passenger = 0;
	int mostpassenger = 0;
	// if not valid return -1
	if (!isValidElevatorString(elevatorstring)) {
		return -1;
	}
	for (int index = 0; index < elevatorstring.length(); index++)
	{
		if (elevatorstring[index] == '+')
		{
			// add
			size_t numberindex = index + 1;
			passenger = passenger + extractNumber(elevatorstring, numberindex);
		}
		if (elevatorstring[index] == '-')
		{
			// subtract and find if passenger count go negative
			size_t numberindex = index + 1;
			passenger = passenger - extractNumber(elevatorstring, numberindex);
		}
		// check if current passengers are more than last recorded
		if (passenger > mostpassenger)
		{
			mostpassenger = passenger;
		}
	}
	return mostpassenger;
}

int endingFloor(string elevatorstring)
{
	// if not valid return -1
	if (!isValidElevatorString(elevatorstring)) {
		return -1;
	}
	// find last M
	size_t index = elevatorstring.find_last_of('M') + 1;
	// convert that to int
	int floor = extractNumber(elevatorstring, index);
	return floor;
}

int highestFloor(string elevatorstring)
{
	// lowest possible floor is 0
	int highestfloor = 0;
	// if not valid return -1
	if (!isValidElevatorString(elevatorstring)) {
		return -1;
	}
	// loop through all M
	for (int index = 0; index < elevatorstring.length(); index++)
	{
		if (elevatorstring[index] == 'M')
		{
			size_t numberindex = index + 1;
			int floor = extractNumber(elevatorstring, numberindex);
			// if higher change highest floor to that value
			if (highestfloor < floor)
			{
				highestfloor = floor;
			}
		}
	}
	return highestfloor;
}

int main()
{
	// empty string
	assert(isValidElevatorString("") == false);
	// does not start with M
	assert(isValidElevatorString("OC") == false);
	assert(isValidElevatorString("+1-1+5M3") == false);
	// invaid elevator string
	assert(doorsOpen("M-10") == false);
	assert(endingPassengers("M1+1-10") == -1);
	assert(mostPassengers("M1-10") == -1);
	assert(endingFloor("M1M2M-3") == -1);
	assert(highestFloor("M10-5") == -1);
	assert(isValidElevatorString("M1COC") == false);
	// valid strings
	assert(isValidElevatorString("M1O+3-2C"));
	assert(doorsOpen("M1O+3-2C") == false);
	assert(doorsOpen("M1OCOCOCO") == true);
	assert(endingPassengers("M1O+3-2CO+10") == 11);
	assert(endingPassengers("M1O+00000000000000001") == 1);
	assert(mostPassengers("M1O+3-2C") == 3);
	assert(mostPassengers("M1O+010000-100") == 10000);
	assert(endingFloor("M1O+3-2C") == 1);
	assert(endingFloor("M1O+1+2CM00010010") == 10010);
	assert(highestFloor("M1O+3-2C") == 1);
	assert(highestFloor("M1OCOCOCM200M100") == 200);
	assert(endingPassengers("M1O+0+0+0+1") == 1);

	cout << "All tests succeeded" << endl;
	return 0;
}