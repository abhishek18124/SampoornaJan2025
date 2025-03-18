/*

ngr => current ques => rev your ans
ngl => scan the arr[] from left to right i.e. 0 to n-1
nsr => change the sign from <= to >= while popping elements from the stk, also rev your ans
nsl => scan the arr[] from left to right and change sign from <= to >= while popping elements from the stk

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main() {

	int arr[] = {2, 0, 1, 3, 5, 4};
	int n = 6;

	stack<int> stk;
	vector<int> ans; // to track the nearest greater element to the right
	// for each element of the arr[]

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of arr[i]

		while (!stk.empty() and stk.top() <= arr[i]) {
			// element at the top of stk cannot be the nearest greater element
			// to the right of arr[i]
			stk.pop();
		}

		if (stk.empty()) {
			// there is no nearest greater element to the right of arr[i]
			ans.push_back(-1);
		} else {
			// element at the top of the stk is the nearest greater element
			// to the right of arr[i]
			ans.push_back(stk.top());
		}

		stk.push(arr[i]);

	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}