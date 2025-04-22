// design a recursive algorithm to digit-wise generate nos. from 0000 to 2345

#include<iostream>

using namespace std;

void f(const string& inp, string& out, int i) {

	// base case

	if (i == inp.size()) {
		cout << out << endl;
		return;
	}

	// recursive case

	// decide the ith digit

	bool isPrefixSame = true; // assume inp[0...i-1] matches out[0...i-1]

	for (int j = 0; j < i; j++) {
		if (inp[j] != out[j]) {
			isPrefixSame = false;
			break;
		}
	}

	int upperBound = isPrefixSame ? inp[i] - '0' : 9;

	for (int d = 0; d <= upperBound; d++) {

		// use 'd' as the ith digit

		out.push_back(d + '0');
		f(inp, out, i + 1);
		out.pop_back(); // backtrack

	}

}

int main() {

	string inp = "2345";
	string out = "";

	f(inp, out, 0);

	return 0;
}