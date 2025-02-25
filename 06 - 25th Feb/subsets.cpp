// https://leetcode.com/problems/subsets/
class Solution {
public:

    void f(const vector<int>& nums, int i, vector<int>& out, vector<vector<int>>& allSubsets) {

        // base case

        if (i == nums.size()) {
            allSubsets.push_back(out);
            return;
        }

        // recursive case

        // f(i) = take decisions for the remaining elements nums[i...n-1]
        // f(i) = generate subsequences / subsets for nums[i...n-1]

        // make a decision for nums[i]

        // option 1 : include nums[i] to the out[]

        out.push_back(nums[i]);
        f(nums, i + 1, out, allSubsets);
        out.pop_back(); // backtracking

        // option 2 : exclude nums[i] from the out[]

        f(nums, i + 1, out, allSubsets);

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allSubsets; // to track all subsets
        vector<int> out; // to track a single subset
        f(nums, 0, out, allSubsets);

        return allSubsets;

    }
};