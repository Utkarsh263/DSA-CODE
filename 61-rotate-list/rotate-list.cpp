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
    ListNode* findnthNode(ListNode* head, int k){
        int cnt = 1;
        while(head != NULL){
            if(cnt ==k ){
                return head;
            }
            cnt++;
            head= head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head== NULL || k==0 || head->next == NULL){
            return head;
        }
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }

        if(k % len ==0){ // if len = 5 and k = 10, 15 no rotation
            return head;
        }

        k = k % len;
        tail->next = head;
        ListNode* lastNode = findnthNode(head, len-k);

        head = lastNode->next;
        lastNode->next = NULL;

        return head;
    }
};