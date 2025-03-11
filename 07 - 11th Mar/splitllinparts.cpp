// https://leetcode.com/problems/split-linked-list-in-parts/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int findLen(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans;

        int n = findLen(head);
        int lenOfEachPart = n / k;
        int remainingNodes = n % k;

        for (int j = 1; j <= k; j++) {
            ans.push_back(head);
            int oneMoreIteration = remainingNodes > 0 ? 1 : 0;
            for (int i = 0; i < lenOfEachPart - 1 + oneMoreIteration; i++) {
                head = head->next;
            }
            remainingNodes--;
            if (head != NULL) {
                ListNode* temp = head->next;
                head->next = NULL;
                head = temp;
            }
        }

        return ans;

    }
};