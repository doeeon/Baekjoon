#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	string str;
	vector<string> list(n, "");
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		list[i] = str;
	}

	sort(list.begin(), list.end());

	vector<string> answer;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (binary_search(list.begin(), list.end(), str))
			answer.push_back(str);
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';

	return 0;
}