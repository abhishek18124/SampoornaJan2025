#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		int n = nums.size();

		sort(nums.begin(), nums.end());

		vector<vector<int>> ans;

		// fix the 1st element of the potential triplet

		for (int i = 0; i < n - 2; i++) {

			if (nums[i] > 0) break;

			if (i > 0 and nums[i] == nums[i - 1]) continue;

			int targetSum = -nums[i];

			// look for pairs in nums[i+1...n-1] whose sum is equal to targetSum

			// using 2-pointer approach

			int j = i + 1;
			int k = n - 1;

			while (j < k) {

				int pairSum = nums[j] + nums[k];

				if (pairSum == targetSum) {

					// you've found a valid triplet

					ans.push_back({nums[i], nums[j], nums[k]});
					j++;
					k--;

					while (j < k and nums[j] == nums[j - 1]) j++;
					while (j < k and nums[k] == nums[k + 1]) k--;


				} else if (pairSum > targetSum) {

					k--;

				} else {
					// pairSum < targetSum

					j++;

				}

			}

		}


		return ans;

	}
};
