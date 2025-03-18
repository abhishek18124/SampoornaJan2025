#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {

	int arr[] = {2, 0, 1, 3, 5, 4};
	int n = sizeof(arr) / sizeof(int);

	vector<int> ans(n, -1);
	stack<int> stk; // to track indices of elements for which we are yet to
	// find the nearest greater element to right

	for (int i = 0; i < n; i++) {

		// what are elements for which arr[i] can the ans ?

		while (!stk.empty() and arr[i] > arr[stk.top()]) {
			// arr[i] is the nearest greater element to the right
			// of element whose index is present at the top of the
			// stk
			ans[stk.top()] = arr[i];
			stk.pop();
		}

		stk.push(i);

	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}