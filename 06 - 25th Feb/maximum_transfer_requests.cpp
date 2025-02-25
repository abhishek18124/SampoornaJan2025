// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
class Solution {
public:

    int maxSofar = 0;

    void f(const vector<vector<int>>& requests, int i, int cnt, vector<int>& netmov) {

        // base case

        if (i == requests.size()) { // you've taken decisions for all the requests

            // verify the validity of your decisions

            bool flag = true; // assume all decisions were valid
            for (int i = 0; i < netmov.size(); i++) { // verify your assumption by making sure netmov in each buidling is 0
                if (netmov[i] != 0) {
                    flag = false; // there is a building with netmov being non-zero, so decisions were invalid
                    break;
                }
            }

            if (flag) {
                maxSofar = max(maxSofar, cnt);
            }

            return;

        }

        // recursive case

        // f(i) : take decisions for the remaining requests

        // make a decision for the ith request

        int from_i = requests[i][0];
        int to_i   = requests[i][1];

        // option 1 : accept the ith request

        cnt++;
        netmov[from_i]--;
        netmov[to_i]++;

        f(requests, i + 1, cnt, netmov);

        cnt--; // backtracking
        netmov[from_i]++; // backtracking
        netmov[to_i]--; // backtracking

        // option 2 : reject the ith request

        f(requests, i + 1, cnt, netmov);


    }

    int maximumRequests(int n, vector<vector<int>>& requests) {

        vector<int> netmov(n, 0);
        f(requests, 0, 0, netmov);
        return maxSofar;

    }
};