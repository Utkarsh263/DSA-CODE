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

 // Instead of creating new nodes, play with pointers 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next != NULL){

            //reconnect pointer
            odd->next = even->next;
            // Iterate
            odd= odd->next;

            // Similarly for Even indices
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};