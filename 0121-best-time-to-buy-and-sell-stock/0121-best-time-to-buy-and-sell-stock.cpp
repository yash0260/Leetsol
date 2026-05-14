class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n= prices.size();
      int profit=0;  
      int bought=prices[0];
      for(int i=1;i<n;i++){
        if (bought>prices[i]){
            bought=prices[i];
        }else if( prices[i]-bought>profit){
            profit=prices[i]-bought;
        }else{
            
        }
      }
      return profit;
    }
};