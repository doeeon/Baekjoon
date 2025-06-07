#include <iostream>

using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;

	int day;

	day = (V - A + (A - B - 1)) / (A - B) + 1;
	// A-B-1은 올림 위해 필요

	cout << day;
	return 0;
}

// 하루에 (A-B)만큼 전진.
// 마지막 날은 미끄러지지 않음 = A 만큼 전진
// V-A까지는 (A-B) 속도로 진행
// 마지막날엔 A만큼 전진하고 끝