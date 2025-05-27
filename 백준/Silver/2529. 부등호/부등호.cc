#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool Check(vector<int> num, vector<char> v_c)
{
	for (int i = 0; i < v_c.size(); i++)
	{
		if (v_c[i] == '<')
		{
			if (num[i] >= num[i + 1])
				return false;
		}
		else
		{
			if (num[i] <= num[i + 1])
				return false;
		}
	}

	return true;
}

int main() {
	int N;
	cin >> N;

	vector<char> v_c;
	vector<int> v_min;
	vector<int> v_max;
	char c;
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		v_c.push_back(c);
	}
	for (int i = 0; i <= N; i++)
	{
		v_min.push_back(i);
		v_max.push_back(9 - i);
	}

	do {
		if (Check(v_max, v_c))
			break;
	} while (prev_permutation(v_max.begin(), v_max.end()));

	do {
		if (Check(v_min, v_c))
			break;
	} while (next_permutation(v_min.begin(), v_min.end()));

	string ans1 = "";
	string ans2 = "";
	for (int i = 0; i < N + 1; i++)
	{
		ans1 += v_max[i] + '0';
		ans2 += v_min[i] + '0';
	}

	cout << ans1 << '\n' << ans2;

	return 0;
}