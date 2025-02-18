#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {1, 4, 2, 7, 6, 3, 5};
	int n = arr.size();

	int k = 4;

	// time : O(n)
	// space: O(1)

	int i = 0; // to repr. the start of the window
	int j = 0; // to repr. the end of the window

	// 1. find out the sum for the 1st window

	int wsum = 0; // to track window sum

	while (j < k) {
		wsum += arr[j];
		j++;
	}

	int msf = wsum; // assume sum of the 1st window is the maximum window sum you've seen so far

	while (j < n) {

		// slide the window
		wsum -= arr[i];
		i++;
		wsum += arr[j];

		// update the ans
		msf = max(msf, wsum);

		// continue the process
		j++;

	}

	cout << msf << endl;

	return 0;
}