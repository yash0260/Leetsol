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
    int pairSum(ListNode* head) {
        int length=0;
        ListNode*temp=head;
        while(temp!=nullptr){
    length++;
      temp=temp->next;
        }
        temp=head;
        vector<int>arr(length);
        for(int i=0;i<length;i++){
            arr[i]=temp->val;
            temp=temp->next;
        }
        long long ans=INT_MIN;
        int n=length;
        for(int i=0;i<n/2;i++){
long long sum=arr[i]+arr[n-i-1];
ans=max(ans,sum);
        }
        return ans;
    }
};