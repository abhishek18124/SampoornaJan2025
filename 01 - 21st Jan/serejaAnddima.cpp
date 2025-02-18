#include<iostream>
#include<vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int lo = 0;
    int hi = n - 1;

    int s1 = 0; // to track sereja's score
    int s2 = 0; // to track dima's score

    bool serejaTurn = true;

    while (lo <= hi) {

        if (serejaTurn) {

            if (v[lo] > v[hi]) {

                s1 += v[lo];
                lo++;

            } else {

                s1 += v[hi];
                hi--;

            }

            serejaTurn = false;

        } else {

            if (v[lo] > v[hi]) {

                s2 += v[lo];
                lo++;

            } else {

                s2 += v[hi];
                hi--;

            }

            serejaTurn = true;

        }
    }

    cout << s1 << " " << s2 << endl;

    return 0;
}