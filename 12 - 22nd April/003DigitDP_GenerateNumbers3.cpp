// design a recursive algorithm to digit-wise generate nos. from 0000 to 2345

#include<iostream>

using namespace std;

void f(const string& inp, string& out, int i, bool isPrefixSame) {

	// base case

	if (i == inp.size()) {
		cout << out << endl;
		return;
	}

	// recursive case

	// decide the ith digit

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	// int upperBound;
	// if(isPrefixSame) {
	// 	upperBound = inp[i] - '0';
	// } else {
	// 	upperBound = 9;
	// }

	for (int d = 0; d <= upperBound; d++) {

		// use 'd' as the ith digit

		out.push_back(d + '0');
		f(inp, out, i + 1, isPrefixSame and d == upperBound);
		out.pop_back(); // backtrack

	}

}

int main() {

	string inp = "2345";
	string out = "";

	f(inp, out, 0, true);

	return 0;
}