#include<iostream>
#include<set>

// 1. set<> stores distinct values
// 2. all ops. on set<> take logn
// 3. all elements are stored in set<> in sorted order

using namespace std;

int main() {

	multiset<int> s;

	s.insert(3);
	s.insert(1);
	s.insert(4);
	s.insert(2);
	s.insert(5);

	cout << s.size() << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	cout << *s.begin() << endl;
	cout << *s.rbegin() << endl;

	s.insert(1);

	cout << s.size() << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	// s.erase(1); // it will erase all occ. of 1s

	s.erase(s.find(1)); // it will erase only 1st occ. of 1

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;


	return 0;
}