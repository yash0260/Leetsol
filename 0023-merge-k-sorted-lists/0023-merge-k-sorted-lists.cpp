class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0){
            return NULL;
        }

        vector<int> arr;

        // Step 1: Extract all node values
        for(int i = 0; i < n; i++) {
            ListNode* temp = lists[i];
            while(temp != NULL) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }

        // Step 2: Sort the values
        sort(arr.begin(), arr.end());

        // Step 3: Create new sorted linked list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        for(int i = 0; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }

        // Step 4: Return head of the new list
        return dummyNode->next;
    }
};