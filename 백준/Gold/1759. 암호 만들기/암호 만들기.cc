#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool CheckCondition(string str)
{
	int consonant = 0; //자음
	int vowel = 0; //모음(a e i o u)

	for (auto c : str)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			vowel++;
		else
			consonant++;
	}

	if (vowel >= 1 && consonant >= 2)
		return true;
	return false;
}

void Backtracking(int depth, int idx, int L, int C, vector<char>& alpha, string& str)
{
	if (depth == L)
	{
		if(CheckCondition(str))
			cout << str << endl;
		return;
	}

	for (int i = idx; i < C; i++)
	{
		str.push_back(alpha[i]);
		Backtracking(depth + 1, i + 1, L, C, alpha, str);
		str.pop_back();
	}

}

int main()
{
	int L, C;
	cin >> L >> C;

	vector<char> alpha(C);
	for (int i = 0; i < C; i++)
		cin >> alpha[i];

	sort(alpha.begin(), alpha.end());

	string str;
	Backtracking(0, 0, L, C, alpha, str);

	return 0;
}