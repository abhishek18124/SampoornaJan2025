#include<iostream>
#include<vector>
#define int long long

using namespace std;

int32_t main() {

	int n, q;
	cin >> n >> q;

	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	vector<int> psum(n + 1);
	psum[0] = 0;
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + x[i - 1];
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << psum[b + 1] - psum[a] << endl;
	}

	return 0;
}