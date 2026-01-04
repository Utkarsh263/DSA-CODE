/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;
        Node* curr = head;

        // Step 1: Create copy of each node
        while (curr != NULL) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Assign next and random pointers
        curr = head;
        while (curr != NULL) {
            mp[curr]->next = curr->next ? mp[curr->next] : NULL;
            mp[curr]->random = curr->random ? mp[curr->random] : NULL;
            curr = curr->next;
        }

        // Head of copied list
        return mp[head];
    }
};
