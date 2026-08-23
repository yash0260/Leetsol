class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap: stores {node value, node pointer}
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // Put the first node of every list into the heap
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()) {

            // Get the smallest node
            auto [value, node] = pq.top();
            pq.pop();

            // Add it to the merged list
            temp->next = node;
            temp = temp->next;

            // Add the next node from the same list
            if(node->next != nullptr) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};