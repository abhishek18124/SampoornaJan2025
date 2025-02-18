#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	vector<int> v = {1, 2, 1, 1, 3, 4, 4, 2, 1};
	int n = v.size();
	int k = 3;

	int i = 0;
	int j = 0;

	map<int, int> mp;

	while (j < k) {
		mp[v[j]]++;
		j++;
	}

	cout << mp.size() << " ";

	while (j < n) {

		// slide the window
		mp[v[i]]--;
		if (mp[v[i]] == 0) mp.erase(v[i]);
		i++;
		mp[v[j]]++;

		cout << mp.size() << " ";

		j++;

	}

	return 0;
}