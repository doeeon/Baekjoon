#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<char> answer;

	int s_num = 1;
	stack<int> st;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (st.empty())
		{
			st.push(s_num++);
			answer.push_back('+');
		}

		if (st.top() == num)
		{
			st.pop();
			answer.push_back('-');
		}
		else if (st.top() < num)
		{
			if (s_num > num)
			{
				answer.push_back('N');
				break;
			}
			else
			{
				while (s_num <= num)
				{
					st.push(s_num++);
					answer.push_back('+');
				}
				st.pop();
				answer.push_back('-');
			}
		}
		else
		{
			while (!st.empty() && st.top() != num)
			{
				st.pop();
				answer.push_back('-');
			}

			if (st.empty())
			{
				answer.push_back('N');
				break;
			}
			else
			{
				st.pop();
				answer.push_back('-');
			}
		}
	}

	if (answer.back() == 'N')
		cout << "NO";
	else
		for (auto c : answer)
			cout << c << '\n';

	return 0;
}