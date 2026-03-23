class Solution {
public:
 bool compare(vector<int>&arr,int mid,int k){
      long long pages=0;
      int students=1;
      for(int i=0;i<arr.size();i++){
          if(pages+arr[i]<=mid){
              pages+=arr[i];
          }
          else{
              pages=arr[i];
              students++;
          }
          
      }
      if(students>k){
          return false;
      }
      return true;
  }
    int splitArray(vector<int>& nums, int k) {
        // code here
        if(k > nums.size()) return -1;
        int low =*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
                    int mid=low+(high-low)/2;

         if (compare(nums,mid,k)){
             high=mid-1;
         }else{
             low=mid+1;
         }
        }
        return low;
    }
};