class Solution {
    int check(int a){
        int sum=0;
while(a > 0){
            sum += a % 10;
            a /= 10;
}
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
      int n=nums.size();
      int ans=INT_MAX;
      for(int i=0;i<n;i++){
        nums[i]=check(nums[i]);
         ans=min(ans,nums[i]);
      }
     
      return ans;  
    }
};