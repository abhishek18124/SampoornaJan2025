// design a recursive algorithm to count the no. of nos. from 0 to inp whose sum of digits is divisible by k

// inp <= 1e1000
// k <= 200

#include<iostream>
#include<cstring>

using namespace std;

int memo[20][2][200]; // 0<=i<=18 0<=isSamePrefix<=1 0<=digitSumMod<=k-1
string inp;
int n, k;

int f(int i, bool isSamePrefix, int digitSumMod) {

	// digitSumMod is used instead of digitSum since digitSum can become very high when no. of digits in inp inc. eg. 1e10000000 etc.

	// base case

	if (i == n) {

		if (digitSumMod == 0) {
			return 1;
		}

		return 0;

	}

	// lookup

	if (memo[i][isSamePrefix][digitSumMod] != -1) {
		return memo[i][isSamePrefix][digitSumMod];
	}

	// recursive case

	// decide the ith digit

	int upperBound = isSamePrefix ? inp[i] - '0' : 9;

	int cnt = 0;

	for (int d = 0; d <= upperBound; d++) {

		// choose 'd' as the ith digit

		cnt += f(i + 1, isSamePrefix and d == upperBound, (digitSumMod + d) % k);

	}

	return memo[i][isSamePrefix][digitSumMod] = cnt;

}

int main() {

	cin >> inp;
	n = inp.size();

	cin >> k;

	memset(memo, -1, sizeof(memo));

	cout << f(0, true, 0);

	return 0;
}