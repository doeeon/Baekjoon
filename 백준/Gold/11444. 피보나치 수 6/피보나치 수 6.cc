#include <iostream>
#include <vector>

using namespace std;

#define DIV 1000000007

vector<vector<long long>> MultipleMatrix(vector<vector<long long>>& A, vector<vector<long long>>& B)
{
	vector<vector<long long>> C(2, vector<long long>(2, 0));

	C[0][0] = ((A[0][0] * B[0][0]) % DIV + (A[0][1] * B[1][0]) % DIV) % DIV;
	C[0][1] = ((A[0][0] * B[0][1]) % DIV + (A[0][1] * B[1][1]) % DIV) % DIV;
	C[1][0] = ((A[1][0] * B[0][0]) % DIV + (A[1][1] * B[1][0]) % DIV) % DIV;
	C[1][1] = ((A[1][0] * B[0][1]) % DIV + (A[1][1] * B[1][1]) % DIV) % DIV;

	return C;
}

vector<vector<long long>> PowerMatrix(long long n, vector<vector<long long>>& M)
{
	if (n == 1)
		return M;

	vector<vector<long long>> T = PowerMatrix(n / 2, M); // Divide

	vector<vector<long long>> R = MultipleMatrix(T, T); // Conquer

	if (n % 2 == 1)
		R = MultipleMatrix(R, M);

	return R;
}

int main()
{
	// (Fn+1) = M(Fn  ) = (1 1)(Fn  ) = M^n(F1) = M^(n/2) * M^(n/2) (F1)
	// (Fn	) =	 (Fn-1) = (1 0)(Fn-1) =	   (F0) =					(F0)

	// Fn = M^n[1][0]

	// 분할 정복
	// M^n = M^(n/2) * M^(n/2) (if n % 2 == 0)
	// M^n = M^((n-1)/2) * M^((n-1)/2) * M (if n % 2 == 1)

	long long n;

	cin >> n;

	vector<vector<long long>> m = { {1, 1}, {1, 0} };
	vector<vector<long long>> result = PowerMatrix(n, m);

	cout << result[1][0];

	return 0;
}