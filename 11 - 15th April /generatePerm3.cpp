// n <= 10

#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int n, const string& v, string ans, int bitmask) {

	// base case

	if (bitmask == (1 << n) - 1) { // ans.size() == v.size()
		// you've built a permuation
		cout << ans << endl;
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

		generatePermutations(n, v, ans + v[j], bitmask | (1 << j));

	}

}

int main() {

	string v = "123";
	int n = v.size();
	string ans; // to track a single permuation

	generatePermutations(n, v, ans, 0);

	return 0;
}