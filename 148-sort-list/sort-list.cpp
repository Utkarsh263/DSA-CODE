class Solution {
public:
    // Step 1: Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1 != NULL) ? l1 : l2;
        return dummy.next;
    }

    // Step 2: Merge sort main function
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }
};
