#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string op;
		cin >> op;
		
		bool flip = false;
		int pop_back_cnt = 0;
		int pop_front_cnt = 0;
		for (int i = 0; i < op.size(); i++)
		{
			if (op[i] == 'R')
				flip = !flip;
			else
			{
				if (!flip)
					pop_front_cnt++;
				else
					pop_back_cnt++;
			}
		}

		int n;
		string snum;
		cin >> n >> snum;

		if (n - pop_front_cnt - pop_back_cnt < 0)
		{
			cout << "error\n";
			continue;
		}

		snum = snum.substr(1, snum.size() - 2);

		vector<string> v(1,"");
		for (int i = 0; i < snum.size(); i++)
		{
			if (isdigit(snum[i]))
				v.back() += snum[i];
			else
				v.push_back("");
		}

		vector<string> pv(v.begin() + pop_front_cnt, v.end() - pop_back_cnt);

		if (flip)
			reverse(pv.begin(), pv.end());

		string answer = "[";
		for (int i = 0; i < pv.size(); i++)
			answer += pv[i] + ',';

		if (answer.back() == ',')
			answer.back() = ']';
		else
			answer += ']';


		cout << answer << '\n';
	}

	return 0;
}