#include <iostream>
#include <string>
#include <vector>
using namespace std;

int FIZZBUZZ(int n)
{
	if (n % 3 == 0 && n % 5 == 0)
		return -1; // FizzBuzz
	else if (n % 3 == 0)
		return -2; // Fizz
	else if (n % 5 == 0)
		return -3; // Buzz
	else
		return n; // n
}

int main() {
	string str;
	vector<int> input(3, 0);
	for (int i = 0; i < 3; i++)
	{
		cin >> str;
		if (str == "FizzBuzz")
			input[i] = -1;
		else if (str == "Fizz")
			input[i] = -2;
		else if (str == "Buzz")
			input[i] = -3;
		else
			input[i] = stoi(str);
	}

	
	for (int i = 1; i <= 1e9-3; i++)
	{
		if (FIZZBUZZ(i) == input[0] && FIZZBUZZ(i + 1) == input[1] && FIZZBUZZ(i + 2) == input[2])
		{
			int ans = FIZZBUZZ(i+3);
			if (ans == -1)
				cout << "FizzBuzz";
			else if (ans == -2)
				cout << "Fizz";
			else if (ans == -3)
				cout << "Buzz";
			else
				cout << ans;
			break;
		}
	}
	return 0;
}