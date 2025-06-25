#include <iostream>
#include <cmath>

using namespace std;

int MUL(int A, int B, int C)
{
	if (B == 1)
		return A % C;
	
	long long half = MUL(A, B / 2, C);
	long long result = (half * half) % C;

	if (B % 2 == 1)
		return (result * A) % C;
	else
		return result;
}


int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	long long answer;
	answer = MUL(A, B, C);

	cout << answer;
	return 0;
}