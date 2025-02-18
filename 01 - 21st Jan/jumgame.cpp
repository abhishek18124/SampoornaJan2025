#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {

		int n = nums.size();
		int maxReachableIndex = 0;

		for (int i = 0; i < n; i++) {

			if (i > maxReachableIndex) {

				return false;

			}

			// you can reach index i

			if (i + nums[i] > maxReachableIndex) {

				maxReachableIndex = i + nums[i];

			}

			// maxReachableIndex = max(maxReachableIndex, i + nums[i]);

		}

		return true;

	}
};

int main() {

	vector<int> nums = {2, 1, 1, 0, 4};

	Solution s;
	cout << s.canJump(nums) << endl;

	return 0;
}