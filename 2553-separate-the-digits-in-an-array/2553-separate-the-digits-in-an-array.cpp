class Solution {
public:
void aj(int a,vector<int>&ans){
      string s=to_string(a);
      int n=s.size();
      for(int i=0;i<n;i++){
             int ak =s[i]-'0';
ans.push_back(ak);
      }
}
    vector<int> separateDigits(vector<int>& nums) {
      int n=nums.size();
      vector<int> ans;
      for(int i=0;i<n;i++){
        aj(nums[i],ans);
      }
      return ans;  
    }
};