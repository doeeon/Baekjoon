#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// vector와 map 둘 다 저장
	// vector -> v[idx] = name
	// map -> m.find(name) = idx

	int N, M;
	cin >> N >> M;

	string str;
	vector<string> v_dict(N + 1, "");
	map<string, int> m_dict;
	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		v_dict[i] = str;
		m_dict[str] = i;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (isdigit(str.front()))
			cout << v_dict[stoi(str)] << '\n';
		else
			cout << m_dict[str] << '\n';
	}

	return 0;
}