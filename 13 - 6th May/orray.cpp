#include<iostream>
#include<vector>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int prefixOR = 0;
		vector<bool> taken(n, false);
		vector<int> ans; // to track the rearrangement for which the prefix OR array is lexicographically maximum

		for (int i = 0; i < 32; i++) {

			// pick the ith element to be put in ans[]

			int maxSofar = 0;
			int idx;
			bool found = false;

			for (int j = 0; j < n; j++) {

				if (!taken[j] and (a[j] | prefixOR) > maxSofar) {

					maxSofar = a[j] | prefixOR;
					idx = j;
					found = true;

				}

			}

			if (found) {
				taken[idx] = true;
				ans.push_back(a[idx]);
				prefixOR = maxSofar; // update prefixOR for the next iteration
			} else {
				break;
			}

		}

		for (int i = 0; i < n; i++) {
			if (!taken[i]) {
				ans.push_back(a[i]);
			}
		}

		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}

		cout << endl;

	}

	return 0;
}