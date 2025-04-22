// design a recursive algorithm to find the sum of digits of all the nos. from 0000 to 2345

#include<iostream>

using namespace std;

int f(const string& inp, string& out, int i, bool isPrefixSame, int digitSum) {

	// base case

	if (i == inp.size()) {
		cout << "sum(" << out << ") = " << digitSum << endl;
		return digitSum;
	}

	// recursive case

	// decide the ith digit

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	int totalSum = 0;

	for (int d = 0; d <= upperBound; d++) {

		// use 'd' as the ith digit

		out.push_back(d + '0');
		totalSum += f(inp, out, i + 1, isPrefixSame and d == upperBound, digitSum + d);
		out.pop_back(); // backtrack

	}

	return totalSum;

}

int main() {

	string inp = "2345";
	string out = "";

	cout << f(inp, out, 0, true, 0) << endl;

	return 0;
}