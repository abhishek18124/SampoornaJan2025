#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}

	// for (int i = 0; i < n; i++) {
	// 	cin >> v[i].first >> v[i].second;
	// }

	// sort(v.begin(), v.end(), cmp);

	sort(v.begin(), v.end());

	int ans = 0;
	int prevEndTime = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second >= prevEndTime) {
			ans++;
			prevEndTime = v[i].first;
		}
	}

	cout << ans << endl;

	return 0;
}