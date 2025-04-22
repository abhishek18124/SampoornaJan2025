// design a recursive algorithm to count the no. of nos. from 0 to inp whose sum of digits is equal to k

// inp <= 1e18

#include<iostream>
#include<cstring>

using namespace std;

int memo[20][2][200]; // 0<=i<=18 0<=isSamePrefix<=1 0<=digitSum<=163
string inp;
int n, k;

int f(int i, bool isSamePrefix, int digitSum) {

	// base case

	if (i == n) {

		if (digitSum == k) {
			return 1;
		}

		return 0;

	}

	// lookup

	if (memo[i][isSamePrefix][digitSum] != -1) {
		return memo[i][isSamePrefix][digitSum];
	}

	// recursive case

	// decide the ith digit

	int upperBound = isSamePrefix ? inp[i] - '0' : 9;

	int cnt = 0;

	for (int d = 0; d <= upperBound; d++) {

		// choose 'd' as the ith digit

		cnt += f(i + 1, isSamePrefix and d == upperBound, digitSum + d);

	}

	return memo[i][isSamePrefix][digitSum] = cnt;

}

int main() {

	cin >> inp;
	n = inp.size();

	cin >> k;

	memset(memo, -1, sizeof(memo));

	cout << f(0, true, 0);

	return 0;
}