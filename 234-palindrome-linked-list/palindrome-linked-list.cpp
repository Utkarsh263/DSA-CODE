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
    bool isPalindrome(ListNode* head) {
        
        // If no node is present or one node is present 
        if(head == NULL || head->next == NULL){
            return true;
        }

        // Slow and fast pointer to get slow on the middle of Linked List 
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now reversing the Linked List from the middle and will check values of node to find out whether LL  is palindrome or not 
        ListNode* prev = NULL;
        while(slow != NULL){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* a = head;
        ListNode* b = prev;

        while(b != NULL){
            if(a->val != b->val){
                return false;
            }
            a = a->next;
            b = b->next;
        }

        return true;
        
    }
};