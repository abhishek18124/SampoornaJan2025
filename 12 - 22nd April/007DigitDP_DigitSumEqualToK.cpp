// design a recursive algorithm to count the no. of nos. from 0 to 1e5 whose sum of digits is equal to K
#include<iostream>

using namespace std;

string inp = "100000";
int k;

int f(string& out, int i, bool isSamePrefix, int digitSum) {

	// base case

	if (i == inp.size()) {

		cout << "sum(" << out << ") = " << digitSum << endl;

		if (digitSum == k) {
			return 1;
		}

		return 0;

	}

	// recursive case

	// decide the ith digit

	int upperBound = isSamePrefix ? inp[i] - '0' : 9;

	int cnt = 0;

	for (int d = 0; d <= upperBound; d++) {

		// choose 'd' as the ith digit

		out.push_back(d + '0');
		cnt += f(out, i + 1, isSamePrefix and d == upperBound, digitSum + d);
		out.pop_back();

	}

	return cnt;

}

int main() {

	cin >> k;

	string out = "";

	cout << f(out, 0, true, 0);

	return 0;
}