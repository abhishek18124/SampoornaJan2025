// n <= 10

#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int n, const vector<int>& v, vector<int>& ans, int bitmask) {

	// base case

	if (bitmask == (1 << n) - 1) { // ans.size() == v.size()
		// you've built a permuation
		for (auto x : ans) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	// recursive case

	// decide the next element

	for (int j = 0; j < v.size(); j++) {

		// is v[j] a valid option for the next element of the permuation that we are building ?

		if (bitmask & (1 << j)) {
			// jth bit of mask is set therefore v[j] is not a valid option
			continue;
		}

		// jth bit of mask is not set therefore we can choose v[j] as the next
		// element of the permuation

		ans.push_back(v[j]);
		bitmask = bitmask ^ (1 << j); // flipping the jth bit of bitmask from 0 to 1
		// bitmask = bitmask | (1<< j); // setting the jth bit of bitmask
		generatePermutations(n, v, ans, bitmask);
		ans.pop_back(); // backtracking
		bitmask = bitmask ^ (1 << j); // flipping the jth bit of bitmask from 1 to 0
		// bitmask = bitmask & (~(1 << j)); // clearing the jth bit of bitmask
	}

}

int main() {

	vector<int> v = {1, 2, 3};
	int n = v.size();
	vector<int> ans; // to track a single permuation

	generatePermutations(n, v, ans, 0);

	return 0;
}