class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int n=gain.size();
      vector<int>arr(n+1);
      arr[0]=0;
      int ans=0;
      for(int i=1;i<n+1;i++){
arr[i]=arr[i-1]+gain[i-1];
ans=max(arr[i],ans);
      }
      return ans;  
    }
};