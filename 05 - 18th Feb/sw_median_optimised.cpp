class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0; // to repr. the start of the window
        int j = 0; // to repr. the end of the window

        multiset<long long> left;
        multiset<long long> right;

        while (j < k) {
            if (left.size() == right.size()) {
                left.insert(nums[j]); // logk
            } else {
                right.insert(nums[j]);
            }

            if (!right.empty() and * left.rbegin() > *right.begin()) { // logk

                left.insert(*right.begin());
                right.erase(right.begin());
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));

            }

            j++;
        }

        vector<double> ans;
        if (k % 2 == 1) { // we are given an odd-length window // const
            ans.push_back(*left.rbegin());
        } else { // we are given even-length window
            ans.push_back((*left.rbegin() + *right.begin()) / 2.0);
        }

        while (j < n) { // (n-k) * (logk + logk) ~ O(nlogk)

            // slide the window
            if (nums[i] <= *left.rbegin()) { // logk
                // remove nums[i] from left
                left.erase(left.find(nums[i]));
            } else {
                // remove nums[i] from right
                right.erase(right.find(nums[i]));
            }
            i++;

            if (left.size() <= right.size()) { // after removing nums[i], size of left can become < size of right
                left.insert(nums[j]); // logk
            } else {
                right.insert(nums[j]);
            }

            if (!right.empty() and * left.rbegin() > *right.begin()) { // logk

                left.insert(*right.begin());
                right.erase(right.begin());
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));

            }

            // find the median for the current window

            if (k % 2 == 1) { // we are given an odd-length window // const
                ans.push_back(*left.rbegin());
            } else { // we are given even-length window
                ans.push_back((*left.rbegin() + *right.begin()) / 2.0);
            }

            // continue the process

            j++;


        }

        return ans;

    }
};