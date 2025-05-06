#include<iostream>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<pair<long long, int>> contri(32);

		for (int i = 0; i < 32; i++) {

			// find the contribution of the ith bit to the S
			// assuming ith bit of X is set

			long long cnt = 0; // to track how many nos. in a[] has its ith bit as set

			for (int j = 0; j < n; j++) {

				// check if the the ith bit of jth no. in a[] is set or not

				if (a[j] & (1 << i)) {
					cnt++;
				}

			}

			contri[i] = {cnt * (1 << i), i * - 1};

		}

		sort(contri.rbegin(), contri.rend()); // sorting contr[] in dec. order

		int x = 0;

		for (int i = 0; i < k; i++) {

			int bitToSet = abs(contri[i].second);
			x = x | (1 << bitToSet);

		}

		cout << x << endl;

	}

	return 0;
}
