
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;

        while (temp != nullptr) {

            vector<int> arr;
            ListNode* curr = temp;

            // Collect k nodes
            int i = 0;

            while (i < k && curr != nullptr) {
                arr.push_back(curr->val);
                curr = curr->next;
                i++;
            }

            // If fewer than k nodes remain, stop
            if (i < k)
                break;

            // Reverse the values
            reverse(arr.begin(), arr.end());

            // Put reversed values back
            curr = temp;

            int j = 0;

            while (j < k) {
                curr->val = arr[j];
                curr = curr->next;
                j++;
            }

            // Move to the next group
            temp = curr;
        }

        return head;
    }
};