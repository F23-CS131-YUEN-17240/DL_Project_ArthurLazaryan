#include <iostream> // header files used in the algorithm
#include <string>
#include <vector>
using namespace std;

bool LuhnAlgorithm(string); // function prototype for the function which holds the algorithm

int main()
{
	string creditCardNumber = "4417123456789113"; // credit card number that will be parsed and validated

	if (LuhnAlgorithm(creditCardNumber)) // if the card number is valid, which will return a bool true, then the if part of the conditional will run 
		cout << "Valid Credit Card Number" << endl;
	else // if the card number is invalid, the else part of the conditional will run
		cout << "Invalid Credit Card Number" << endl;

	cin.get();

	return 0;
}

bool LuhnAlgorithm(string cardNumber) // function that contains algorithm for the Luhn Algorithm
{
	vector<int> numbers; // each number which is a character in a string will be stored as an integer in the vector
	int sum = 0, result;

	for (int index = 0; index < cardNumber.length(); index++) // parses the string, and converts each character to their numerical ASCII representation using a little bit of the ASCII table
	{
		numbers.push_back(cardNumber[index] - '0');
	}

	for (int index = cardNumber.length() - 2; index >= 0; index = index - 2) // traverses the vector, multiplying the even rank digits in the number from the right
	{
		result = numbers[index] * 2; // multiplies the even rank digits from the right by 2 

		if (result > 9) // tests wheter the result is a double digit which will cause it to add each of the digits
			result = (result % 10) + 1; // modulus operator will return the ones place digit, and the + 1 will acount for the tens place digit

		sum += result; // adds up all of the resultants from the operation
	}

	for (int index = cardNumber.length() - 1; index >= 0; index = index - 2) // traveres the odd digits of the number from the right, adding each of the single digits to the total sum
	{
		sum += numbers[index]; // adds up all of the other digits that are of odd rank, without any special operation done on them
	}

	if (sum % 10) // if the mod is any number other than 0, which means true in c++, so the conditonal will execute, but in the context of the problem it is false, so it will return false
		return false;
	else
		return true; // will return true if the mod is 0

}