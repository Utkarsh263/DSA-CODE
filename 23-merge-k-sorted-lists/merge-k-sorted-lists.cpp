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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Min heap Initialisation 
        priority_queue<ListNode* , vector<ListNode*> , compare>pq;

        // Push head of all lists 
        for(auto node : lists){
            if(node != NULL){
                pq.push(node);
            }
        }

        // Make dummy node and tail pointer

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Start processing  min heap 
        while(!pq.empty()){

            ListNode* smallest = pq.top(); // take the smallest element 
            pq.pop(); // pop from min heap 

            tail->next = smallest; // Append to the list 
            tail = tail->next; // Increment the pointer 

            if(smallest->next != NULL){
                pq.push(smallest->next); // Push next smallest element of the list 
            }
        }

        return dummy->next; // Return the head of the sorted linked list 
    }
};