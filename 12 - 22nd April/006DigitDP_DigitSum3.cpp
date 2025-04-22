// design a recursive algorithm to find the sum of digits of all the nos. from 0000 to 2345

// inp <= 10^9 i.e. 1000000000

#include<iostream>
#include<cstring>

using namespace std;

int memo[20][2][90];

int f(const string& inp, int i, bool isPrefixSame, int digitSum) {

	// base case

	if (i == inp.size()) {
		return digitSum;
	}

	// lookup

	if (memo[i][isPrefixSame][digitSum] != -1) {
		return memo[i][isPrefixSame][digitSum];
	}

	// recursive case

	// decide the ith digit

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	int totalSum = 0;

	for (int d = 0; d <= upperBound; d++) {

		// use 'd' as the ith digit

		totalSum += f(inp, i + 1, isPrefixSame and d == upperBound, digitSum + d);

	}

	return memo[i][isPrefixSame][digitSum] = totalSum;

}

int main() {

	string inp = "2345";

	memset(memo, -1, sizeof(memo));

	cout << f(inp, 0, true, 0) << endl;

	return 0;
}