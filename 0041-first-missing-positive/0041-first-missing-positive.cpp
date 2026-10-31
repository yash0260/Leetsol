class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
          if(st.find(i)!=st.end()){
            continue;
          }else{
            return i;
          }
        }
        return n+1;
    }
};