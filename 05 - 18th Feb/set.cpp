#include<iostream>
#include<set>

// 1. set<> stores distinct values
// 2. all ops. on set<> take logn
// 3. all elements are stored in set<> in sorted order

using namespace std;

int main() {

	set<int> s;

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

	s.insert(1); // since we already have a 1 in set, this 1 will not be inserted

	cout << s.size() << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(2);

	cout << s.size() << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(10);// since 10 is not present, nothing will happen

	s.erase(s.begin()); // we can pass iterators to erase function

	cout << s.size() << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	// s.erase(s.end()); // we should only pass valid iterators to erase otherwise we get error

	// s.erase(s.rbegin()); // this will not work

	// s.erase(s.find(*s.rbegin())); // not needed as set<> has only distinct values
	s.erase(*s.rbegin());

	cout << s.size() << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}