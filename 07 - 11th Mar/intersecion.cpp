// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int findLen(ListNode* head) {
        int cntr = 0;
        while (head) {
            cntr++;
            head = head->next;
        }
        return cntr;
    }

    ListNode* helper(ListNode* biggerHead, ListNode* smallerHead, int diff) {

        // 1. move biggerHead by diff steps to align it with smallerHead

        while (diff--) { // this loop runs diff times
            biggerHead = biggerHead->next;
        }

        while (biggerHead != smallerHead) {
            biggerHead = biggerHead->next;
            smallerHead = smallerHead->next;
        }

        return biggerHead; // or smallerHead

    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = findLen(headA);
        int n = findLen(headB);
        if (m > n) {
            // headA is the bigger linkedList, so move headA by m-n steps
            return helper(headA, headB, m - n);
        } else {
            // headB is the bigger linkedList, so move headB by n-m steps
            return helper(headB, headA, n - m);
        }
    }
};