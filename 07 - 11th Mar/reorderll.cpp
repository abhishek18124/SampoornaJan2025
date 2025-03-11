// https://leetcode.com/problems/reorder-list/

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

    ListNode* findMidPoint(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {

        ListNode* cur = head;
        ListNode* prev = NULL;

        while (cur != NULL) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;

    }

    void reorderList(ListNode* head1) {

        // find the midPoint of the linkedList, and split the linkedList around the midPoint

        ListNode* midPoint = findMidPoint(head1);
        ListNode* head2 = midPoint->next;
        midPoint->next = NULL;

        // 2. reverse the second sublist

        head2 = reverse(head2);

        // 3. interleave 1st and 2nd sublists

        while (head2 != NULL) {
            ListNode* temp = head1->next;
            head1->next = head2;
            head1 = temp;

            temp = head2->next;
            head2->next = head1;
            head2 = temp;
        }

    }
};