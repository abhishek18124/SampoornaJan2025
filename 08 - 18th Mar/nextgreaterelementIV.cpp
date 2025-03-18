class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // ans[i] stores 2nd greater element to the right of arr[i]
        stack<int> stk1; // to track elements for which we are yet to find 1st greater
        stack<int> stk2; // to track elements for which we are yet to find 2nd greater

        for (int i = 0; i < n; i++) {
            // what are the elements for which arr[i] is the ans i.e. 2nd greater element ?
            while (!stk2.empty() and arr[i] > arr[stk2.top()]) {
                // arr[i] is the 2nd greater element to the right of values
                // whose indices are present on top of stk2
                ans[stk2.top()] = arr[i];
                stk2.pop();
            }
            stack<int> temp;
            while (!stk1.empty() and arr[i] > arr[stk1.top()]) {
                // arr[i] is the 1st greater element to the right of values
                // whose indices are present on top of stk1
                temp.push(stk1.top());
                stk1.pop();
            }

            while (!temp.empty()) {
                stk2.push(temp.top());
                temp.pop();
            }

            stk1.push(i);

        }

        return ans;
    }
};