class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int s = 0;
        int e = n - 1;

        while (s <= e) {

            int m = s + (e - s) / 2;

            if (nums[m] == target) {
                // you've found the target at index m
                return m;
            } else {
                if (nums[m] >= nums[s]) {
                    // nums[m] lies in plane 1
                    if (target >= nums[s] and target < nums[m]) {
                        e = m - 1;
                    } else {
                        s = m + 1;
                    }
                } else {
                    // nums[m] lies in plane 2
                    if (target > nums[m] and target <= nums[e]) {
                        s = m + 1;
                    } else {
                        e = m - 1;
                    }
                }
            }
        }

        return -1;

    }
};