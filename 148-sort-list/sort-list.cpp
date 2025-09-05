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
    // Main function
    ListNode* sortList(ListNode* head) {
        // Base case: empty or single node
        if (!head || !head->next) return head;

        // 1. Split list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // break the list

        // 2. Sort each half
        left = sortList(left);
        right = sortList(right);

        // 3. Merge two sorted halves
        return merge(left, right);
    }

private:
    // Function to find middle node (slow/fast pointer)
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // start fast ahead to split properly

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining part
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }
};
