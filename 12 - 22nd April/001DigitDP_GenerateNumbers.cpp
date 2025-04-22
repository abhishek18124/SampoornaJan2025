// design a recursive algorithm to digit-wise generate nos. from 0000 to 9999

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

	for (int d = 0; d <= 9; d++) {

		// use 'd' as the ith digit

		out.push_back(d + '0');
		f(inp, out, i + 1);
		out.pop_back(); // backtrack

	}

}

int main() {

	string inp = "9999";
	string out = "";

	f(inp, out, 0);

	return 0;
}