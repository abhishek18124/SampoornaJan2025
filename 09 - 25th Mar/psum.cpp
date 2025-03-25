#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {3, 2, 4, 5, 1, 1, 5, 3};
	int n = arr.size();

	vector<int> psum(n + 1);
	psum[0] = 0;

	for (int i = 1; i <= n; i++)
		psum[i] = psum[i - 1] + arr[i - 1];

	for (int i = 0; i <= n; i++) {
		cout << psum[i] << " ";
	}

	cout << endl;

	return 0;
}