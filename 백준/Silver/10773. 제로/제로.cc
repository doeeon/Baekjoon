#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int K;
	cin >> K;

	int n;
	vector<int> input;
	for (int i = 0; i < K; i++)
	{
		cin >> n;
		if (n > 0)
			input.push_back(n);
		else
			input.pop_back();
	}

	cout << accumulate(input.begin(), input.end(), 0LL);

	return 0;
}