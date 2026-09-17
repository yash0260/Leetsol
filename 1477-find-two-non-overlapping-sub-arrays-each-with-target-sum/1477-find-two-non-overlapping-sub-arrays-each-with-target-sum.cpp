class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
       int n=arr.size();

        int left = 0;
        int sum = 0;
        const int INF=1e9;
        int ans = INF;
        vector<int>best(n,INF);
        for(int right=0; right<n;right++){
            sum+=arr[right];
            while(sum>target){
                sum-=arr[left];
                left++;
            }
            int len=INF;
            if(sum==target){
                len=right-left+1;
                if(left>0 && best[left-1]!=INF){
                    ans=min(ans,len+best[left-1]);
                }
            }
            if(right>0){
                best[right]=min(best[right-1],len);
            }else{
                best[right]=len;
            }
        }
        if(ans==INF){
            return -1;
        }else{
            return ans;
        }
    }
};