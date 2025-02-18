#include<iostream>
#define int long long

using namespace std;

bool f(int w, int h, int n, int m) {

	int r = m / h;
	int c = m / w;

	return c > 0 and r >= (n + (c - 1)) / c;

}

int32_t main() {

	int w, h, n;
	cin >> w >> h >> n;

	int s = max(w, h);
	int e = max(w, h) * n;

	int ans;

	while (s <= e) {

		int m = s + (e - s) / 2;

		// can I pack n rectangles of dimenstion wxh
		// in a square of dimention mxm ?

		if (f(w, h, n, m)) {
			ans = m;
			e = m - 1;
		} else {
			s = m + 1;
		}

	}

	cout << ans << endl;

	return 0;
}