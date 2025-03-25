#include<iostream>
#include<vector>

using namespace std;

int main() {

	// m : no. of rows
	// n : no. of cols
	// q : no. of queries

	int m, n, q;
	cin >> m >> n >> q;

	vector<vector<int>> arr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> psum(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			psum[i][j] = arr[i][j];
			if (i > 0) psum[i][j] += psum[i - 1][j];
			if (j > 0) psum[i][j] += psum[i][j - 1];
			if (i > 0 and j > 0) psum[i][j] -=  psum[i - 1][j - 1];

			// psum[i][j] = psum[i - 1][j] +
			//              psum[i][j - 1] -
			//              psum[i - 1][j - 1] +
			//              arr[i][j];

			cout << psum[i][j] << " ";

		}
		cout << endl;
	}

	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		int ans = psum[l2][r2];
		if (l1 > 0) ans -= psum[l1 - 1][r2];
		if (r1 > 0) ans -= psum[l2][r1 - 1];
		if (l1 > 0 and r1 > 0) ans += psum[l1 - 1][r1 - 1];

		cout << ans << endl;

		// int ans = psum[l2][r2] -
		//           psum[l1 - 1][r2] -
		//           psum[l2][r1 - 1] +
		//           psum[l1 - 1][r1 - 1];

	}

	return 0;
}