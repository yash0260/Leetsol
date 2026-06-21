class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(costs.begin(),costs.end());
        int cnt=0;
        int i=0;
        while(coins>0 &&  i<n){
        if((long long)costs[i]<=(long long)coins){
            coins=(long long)coins-(long long)costs[i];
            cnt++;
        }else{
            coins=0;
        }
        i++;
        }
return cnt;
    }
};