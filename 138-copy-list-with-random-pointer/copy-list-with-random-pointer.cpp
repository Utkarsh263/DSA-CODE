class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        Node* temp = head;

        // Step 1: Create copy nodes and link them after each original node
        while (temp != NULL) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // Step 2: Assign random pointers for the copy nodes
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next; // move to next original
        }

        // Step 3: Separate the copied list from the interleaved structure
        Node* dummy = new Node(0);
        Node* copyTail = dummy;
        temp = head;

        while (temp != NULL) {
            copyTail->next = temp->next;       // copy node
            temp->next = temp->next->next;     // restore original
            temp = temp->next;
            copyTail = copyTail->next;
        }

        return dummy->next;
    }
};
