class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int ans=-1;
       int small=prices[0];
       for(int i=1;i<n;i++){
        small=min(small,prices[i]);
        if(prices[i]>=small){
        ans=max(ans,(prices[i]-small));
        }

       }
       if(ans!=-1){
       return ans;
       }else{
        return 0;
       }
        
    }
};