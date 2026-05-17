class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        
        int res=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ans=0;
            for(int i=0;i<piles.size();i++){
                ans += (piles[i] + mid - 1LL) / mid;
          }
          
            if(ans>h){
                low=mid+1;
            }else{
                res=mid;
                high=mid-1;
                
            }

        }
        return res;
    }
};