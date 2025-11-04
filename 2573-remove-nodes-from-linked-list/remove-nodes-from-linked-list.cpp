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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nextNode;
        }

        ListNode* newHead = prev;
        int maxVal = newHead->val;
        curr = newHead;

        while(curr && curr->next){
            if(curr->next->val < maxVal){
                curr->next = curr->next->next;

            }else{
                curr= curr->next;
                maxVal = curr->val;
            }
        }

        prev= NULL;
        curr = newHead;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};