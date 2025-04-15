#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1e9 + 7;

int cntr = 0;

int fTopdown(int i, int bitmask, int n, const vector<vector<int>>& a, vector<vector<long long>>& dp) {

	cntr++;

	// base case

	if (bitmask == (1 << n) - 1) {
		// all men are paired up with all women therefore we've built a perm
		return 1;
	}

	// lookup

	if (dp[i][bitmask] != -1) {
		return dp[i][bitmask];
	}

	// recursive case

	// f(i, bitmask) = cnt no. of ways to pair wi...wn-1 with remaining men

	// decide for wi

	long long cnt = 0;

	for (int j = 0; j < n; j++) {

		// can I pair mj with wi ?

		if (a[i][j] == 0) {
			// wi and mj are not compatible therefore they cannot be paired
			continue;
		}

		if (bitmask & (1 << j)) {
			// although wi and mj are compatible but mj is already used so
			// wi and mj cannot be paired
			continue;
		}

		// wi can be paired with mj

		bitmask ^= (1 << j);
		cnt = (cnt + fTopdown(i + 1, bitmask, n, a, dp)) % MOD;
		bitmask ^= (1 << j); // backtracking

	}

	return dp[i][bitmask] = cnt;

}

int main() {

	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	vector<vector<long long>> dp(n, vector<long long>(1 << n, -1));
	cout << fTopdown(0, 0, n, a, dp) << endl;

	cout << cntr << endl;

	return 0;
}