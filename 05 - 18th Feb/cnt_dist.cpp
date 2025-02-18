#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	vector<int> arr = {1, 2, 1, 3, 1, 4, 6, 4};
	int n = arr.size();
	int k = 3;

	int i = 0; // repr. the start of the window
	int j = 0; // repr. the end of the window

	// 1. count no. of distinct elemeets in the 1st window

	map<int, int> mp;

	while (j < k) {
		mp[arr[j]]++;
		j++;
	}

	vector<int> ans;
	ans.push_back(mp.size());

	while (j < n) {

		// slide the window
		mp[arr[i]]--;
		if (mp[arr[i]] == 0) mp.erase(arr[i]);
		i++;
		mp[arr[j]]++;

		ans.push_back(mp.size());

		j++;

	}

	for (auto x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}