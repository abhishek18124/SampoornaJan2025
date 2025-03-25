#include<iostream>
#include<vector>
#include<algorithm>
#define int long long

using namespace std;

int32_t main() {

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> diff(n + 1, 0);

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--; // since we use 0-based indexing and ques uses 1-based indexing
		diff[l] += 1;
		diff[r + 1] -= 1;
	}

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

	sort(a.begin(), a.end());
	sort(diff.begin(), diff.end() - 1);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * diff[i];
	}

	cout << ans << endl;


	return 0;
}