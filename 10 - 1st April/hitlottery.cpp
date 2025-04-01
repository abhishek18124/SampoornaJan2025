#include<iostream>
#include<vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    int ans = 0;
    vector<int> notes = {100, 20, 10, 5, 1};
    for (int note : notes) {
        ans += n / note;
        n = n % note;
    }

    cout << ans << endl;

    return 0;
}