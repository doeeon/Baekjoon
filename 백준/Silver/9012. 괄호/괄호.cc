#include <iostream>
#include <stack>

using namespace std;

string IsVPS(string str)
{
	stack <char> st;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			st.push('(');
		}
		else
		{
			if (st.empty())
				return "NO";
			else
				st.pop();
		}
	}
	
	if (st.empty())
		return "YES";
	else
		return "NO";
}

int main() {
	int T;
	cin >> T;

	string str;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		cout << IsVPS(str) << '\n';
	}

	return 0;
}