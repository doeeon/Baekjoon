#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> arr;
	for (int i = 0; i < N; i++)
		arr.push_back(i + 1);

	cout << "<";
	int idx = 0;
	for (int i = 0; i < N-1; i++)
	{
		idx = (idx + (K - 1)) % arr.size();
		cout << arr[idx] << ", ";

		arr.erase(arr.begin() + idx);
	}
	cout << arr[0] << ">";

	return 0;
}

//1 2 3 4 5 6 7
//1 2   4 5 6 7		3
//1 2   4 5   7		6
//1     4 5   7		2
//1     4 5			7
//1     4			5
//      4			1
//					4

// 3-1 % 7 = 2
// 2+(3-1) % 6 = 4
// 4+2 % 5 = 1
// 1+2 % 4 = 3
