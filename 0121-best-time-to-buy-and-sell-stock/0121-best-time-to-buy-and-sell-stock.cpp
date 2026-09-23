class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN;
        int val=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
ans=max(ans,prices[i]-val);
val=min(prices[i],val);
        }
        return ans;
    }
};