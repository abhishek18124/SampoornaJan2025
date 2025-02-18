#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

bool f(int n, int k, vector<int>& a, double m) {

	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		cnt += a[i] / m; // a[i] / m is no. of pieces we can extract from rope i of length m
	}

	return cnt >= k;

}

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	double s = 0;
	double e = 1e7; // you can also choose max rope length as e

	double ans;

	int numIterations = 50; // log2(1e7 * 1e7)
	double moe = 1e-7; // margin of error, although 1e-6 was need, we go one step beyond to avoid corner cases

	for (int i = 1; i <= numIterations; i++) {

		double m = s + (e - s) / 2;

		// can I take out k pieces of length m from
		// n ropes ?

		if (f(n, k, a, m)) {

			ans = m;
			// move towards the right
			s = m + moe;

		} else {

			// move towards the left
			e = m - moe;

		}

	}

	cout << setprecision(7) << fixed << ans << endl;

	return 0;
}