#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<string> answer;
	for (int i = 0; i < str.size(); i++)
		for (int j = 1; j <= str.size()-i; j++)
			answer.push_back(str.substr(i, j));

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	cout << answer.size();
	return 0;
}