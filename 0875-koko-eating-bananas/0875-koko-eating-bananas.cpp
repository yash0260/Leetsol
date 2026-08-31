class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int n=piles.size();
       int a=INT_MIN;
       for(int i=0;i<n;i++){
         a=max(a,piles[i]);
       }
       long long low=1;
       long long high=a;
       while(low<=high){
        long long mid=low+(high-low)/2;
        long long ans=0;
            for(int i=0;i<piles.size();i++){
                ans += (piles[i] + mid - 1) / mid;
          }
          if(ans>h){
                low=mid+1;
            }else{
                high=mid-1;
                
            }

        }
        return low ;
       } 
};