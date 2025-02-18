class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0; // start of the window
        int j = 0; // end of the window

        multiset<long long> ms;

        while (j < k) {
            ms.insert(nums[j]);
            j++;
        }

        vector<double> ans;
        if (k % 2 == 1) { // we've an odd length window
            auto it = ms.begin();
            for (int l = 0; l < k / 2; l++) {
                it++;
            }
            ans.push_back(*it);
        } else { // we've an even length window
            auto it = ms.begin();
            for (int l = 1; l < k / 2; l++) {
                it++;
            }
            long long a = *it; it++;
            long long b = *it;
            ans.push_back((a + b) / 2.0);
        }

        while (j < n) { // (n-k) * (logk+logk+k/2+c) ~ O(nk)

            // slide the window
            ms.erase(ms.find(nums[i])); // logk
            i++;
            ms.insert(nums[j]); // logk

            // find the median for current window
            if (k % 2 == 1) { // we've an odd length window // k/2
                auto it = ms.begin();
                for (int l = 0; l < k / 2; l++) {
                    it++;
                }
                ans.push_back(*it);
            } else { // we've an even length window
                auto it = ms.begin();
                for (int l = 1; l < k / 2; l++) {
                    it++;
                }
                long long a = *it; it++;
                long long b = *it;
                ans.push_back((a + b) / 2.0);
            }

            // continue the process
            j++;

        }

        return ans;

    }
};