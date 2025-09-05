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
    ListNode* getkthNode(ListNode* temp , int k){
        k -= 1;
        while(temp != NULL && k>0){
            k--;
            temp= temp->next;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!= NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev= curr;
            curr=nextNode;

        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp !=  NULL){
            ListNode* kthNode = getkthNode(temp , k);
            if(kthNode == NULL){
                if(prevLast != NULL){
                    prevLast->next = temp;
                    
                }
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL; // Breaking the list

            reverseList(temp);

            if(temp== head){
                head= kthNode;
            }else{
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;

        }
        return head;
    }
};