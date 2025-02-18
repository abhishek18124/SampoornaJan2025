#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:

    // time : O(n)
    // space: O(n) due to suffMin[]

    // int partitionDisjoint(vector<int>& nums) {

    //     int n = nums.size();
    //     vector<int> suffMin(n);
    //     suffMin[n - 1] = nums[n - 1];

    //     for (int i = n - 2; i >= 0; i--) {
    //         suffMin[i] = min(nums[i], suffMin[i + 1]);
    //     }

    //     int leftMaxSoFar = INT_MIN;
    //     int ans;

    //     for (int i = 0; i < n - 1; i++) {
    //         leftMaxSoFar = max(leftMaxSoFar, nums[i]);
    //         if (leftMaxSoFar <= suffMin[i + 1]) {
    //             // you can make a cut at index i to build a valid partition
    //             ans = i + 1; // i+1 is the smallest length of the left part
    //             break;
    //         }
    //     }

    //     return ans;

    // }

    int partitionDisjoint(vector<int>& nums) {

        int n = nums.size();
        int ans = 1; // assume the min. size of left part is 1

        int leftMaxSofar = nums[0];
        int maxSoFar = nums[0];

        for (int i = 1; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (nums[i] < leftMaxSofar) {
                // old assumption is violated, new assumption 0...i is the left part
                ans = i + 1;
                leftMaxSofar = maxSoFar;
            }
        }

        return ans;

    }
};

int main() {

    vector<int> nums = {5, 0, 3, 8, 6};

    Solution s;

    cout << s.partitionDisjoint(nums) << endl;

    return 0;
}