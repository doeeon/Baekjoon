#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main()
{
	string str;
	cin >> str;

	map<char, int> prior;
	prior['('] = 0;
	prior['+'] = 1;
	prior['-'] = 1;
	prior['*'] = 2;
	prior['/'] = 2;

	stack<char> st;
	string answer = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			answer += str[i];
		else
		{
			if (str[i] == '(')
				st.push(str[i]);
			else if (str[i] == ')')
			{
				while (st.top() != '(')
				{
					answer += st.top();
					st.pop();
				}
				st.pop(); // '(' remove
			}
			else // + - * /
			{
				if (st.empty())
					st.push(str[i]);
				else // compare priority '(' = 0, '+' '-' = 1, '*' '/' = 2
				{
					if (prior[str[i]] <= prior[st.top()])
						while (!st.empty() && st.top() != '(')
						{
							if (prior[str[i]] > prior[st.top()])
								break;

							answer += st.top();
							st.pop();
						}

					st.push(str[i]);
				}
			}
		}
	}
	
	while (!st.empty())
	{
		answer += st.top();
		st.pop();
	}

	cout << answer;
	return 0;
}