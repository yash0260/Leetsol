class Solution {
    
public:
     void check(int a,int& ans,int digit){
         string ab=to_string(a);
         string digi=to_string(digit);
         int n=ab.size();
         for(int i=0;i<n;i++){
             if(ab[i]==digi[0])ans++;
         }
         return;
     }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            check(nums[i],ans,digit);
        }
        return ans;
    }
};