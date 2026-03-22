class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int high=piles[n-1];
        int low=1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long total=0;
for(auto pile:piles){
    total+=(pile+mid-1)/mid;
}
if(total<=h){
ans=mid;
    high=mid-1;
}else{
    low=mid+1;
}

        }
        return ans;
    }
};