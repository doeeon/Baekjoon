#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int Operation(vector<int> op, vector<int> num) {
	int result = num.front();
	for (int i = 0; i < op.size(); i++)
	{
		switch (op[i]) {
		case 0:
			result += num[i + 1];
			break;
		case 1:
			result -= num[i + 1];
			break;
		case 2:
			result *= num[i + 1];
			break;
		case 3:
			result /= num[i + 1];
			break;
		default:
			break;
		}
	}

	return result;
}

int main() {
	int MIN = 1000000000;
	int MAX = -1000000000;
	int N;
	cin >> N;

	vector<int> num;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		num.push_back(n);
	}

	vector<int> op; // + - * /
	for (int i = 0; i < 4; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			op.push_back(i);
	}

	int tmp;
	do {
		tmp = Operation(op, num);
		MAX = max(MAX, tmp);
		MIN = min(MIN, tmp);
	} while (next_permutation(op.begin(), op.end()));


	cout << MAX << endl << MIN;
	return 0;
}