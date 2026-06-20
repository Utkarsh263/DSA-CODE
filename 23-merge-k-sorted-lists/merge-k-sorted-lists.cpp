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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        for(auto node : lists) {
            if(node)
                pq.push({node->val, node});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!pq.empty()) {

            auto [val, curr] = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if(curr->next) {
                pq.push({curr->next->val, curr->next});
            }
        }

        return dummy->next;
    }
};