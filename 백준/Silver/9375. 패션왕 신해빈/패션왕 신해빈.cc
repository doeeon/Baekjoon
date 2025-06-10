#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;

		string str, str2;
		map<string, int> mm;
		for (int i = 0; i < N; i++)
		{
			cin >> str >> str2;
			mm[str2]++;
		}

		int answer = 1;
		for (auto iter = mm.begin(); iter != mm.end(); iter++)
			answer *= (iter->second + 1);

		cout << answer-1 << endl;
	}

	return 0;
}