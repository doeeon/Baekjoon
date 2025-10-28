#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S, M;
	cin >> S >> M;

	string answer = "";

	for (int i = 0; i < S.size(); i++)
	{
		answer += S[i];
		if (S[i] == M.back() && answer.size() >= M.size())
			if (answer.substr(answer.size()-M.size()) == M)
				for (int j = 0; j < M.size(); j++)
					answer.pop_back();
	}

	if (answer.empty())
		cout << "FRULA";
	else
		cout << answer;

	return 0;
}