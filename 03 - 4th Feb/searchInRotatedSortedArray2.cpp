class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                return true;
            } else {
                if (nums[m] > nums[s]) {
                    // you are 100% in plane 1
                    if (target >= nums[s] and target < nums[m]) {
                        e = m - 1;
                    } else {
                        s = m + 1;
                    }
                } else if (nums[m] < nums[e]) {
                    // you are 100% in plane 2
                    if (target > nums[m] and target <= nums[e]) {
                        s = m + 1;
                    } else {
                        e = m - 1;
                    }
                } else {
                    // you can either in plane 1 or in plane 2
                    if (nums[s] == nums[m]) s++;
                    if (nums[e] == nums[m]) e--;
                }
            }
        }

        return false;
    }
};