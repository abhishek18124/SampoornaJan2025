class Solution {
public:

    bool canMake(const vector<int>& nums, int m, int k, int timeLimit) {
        int bouquetCntr = 0;
        int collectCntr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= timeLimit) {
                // ith flower has bloomed, collect the ith flower
                collectCntr++;
                if (collectCntr == k) {
                    // you can now make a bouquet with k adj. flowers collected
                    bouquetCntr++;
                    collectCntr = 0;
                }
            } else {
                // ith flower has not bloomed
                collectCntr = 0;
            }
        }

        return bouquetCntr >= m;
    }

    int minDays(vector<int>& nums, int m, int k) {
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (s <= e) { // time : n.log(e-s)
            int mid = s + (e - s) / 2;
            // Can I make 'm' bouquets of 'k' adj. flowers
            // in mid no. of days ?
            if (canMake(nums, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};