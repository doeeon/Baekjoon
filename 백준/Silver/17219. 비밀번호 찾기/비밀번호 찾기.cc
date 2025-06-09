#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	string str, str2;
	map<string, string> password;
	for (int i = 0; i < N; i++)
	{
		cin >> str >> str2;
		password[str] = str2;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		cout << password[str] << '\n';
	}

	return 0;
}