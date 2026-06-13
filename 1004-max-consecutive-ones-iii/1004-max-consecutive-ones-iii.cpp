class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int n=nums.size();
      int r=0;
      int l=0;
      int len=0;
      while(r<n){
if(nums[r]==1){
    len=max(len,r-l+1);
    r++;
}else if(k>0){
        len=max(len,r-l+1);

    k--;
    r++;
}else{
    if(nums[l]==0){
        k++;
        l++;
    }else{
        l++;
    }
}
      }
      return len;  
    }
};