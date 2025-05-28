#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Combination(vector<int> num)
{
	vector<int> v(num.size(), 1);
	for (int i = 0; i < 6; i++)
		v[i] = 0;

	do {
		for (int i = 0; i < num.size(); i++)
		{
			if (!v[i])
				cout << num[i] << ' ';
		}
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));

}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		
		int tmp;
		vector<int> num;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			num.push_back(tmp);
		}

		Combination(num);
		cout << endl;
	}

	return 0;
}