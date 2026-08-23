class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> visited;

        while (head != NULL) {
            
            if (visited.find(head) != visited.end()) {
                return head;
            }

            visited.insert(head);
            head = head->next;
        }

        return NULL;
    }
};