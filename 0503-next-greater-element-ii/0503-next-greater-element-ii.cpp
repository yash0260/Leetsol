class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
                unordered_map<int,int>nge;
                 stack<int>st;
                 vector<int>nums2;
                 int n=nums.size();
                 for(int i=0;i<n;i++){
                    nums2.push_back(nums[i]);
                 }
                  for(int i=0;i<n;i++){
                    nums2.push_back(nums[i]);
                 }
                 for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty()&& st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top();
            }else{
                nge[i]=-1;
            }
            st.push(nums2[i]);
        }
         vector<int>result;
        for(int i=0;i<nums.size();i++){
            result.push_back(nge[i]);
        }
        return result;

    }
};