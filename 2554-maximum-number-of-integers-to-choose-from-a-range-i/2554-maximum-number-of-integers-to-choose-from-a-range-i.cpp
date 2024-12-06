class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedset(banned.begin(),banned.end());
        int count =0;
        int currentSum=0;
        for (int i=1; i<=n;++i){
            if(bannedset.find(i) == bannedset.end() && currentSum + i <= maxSum){
                currentSum += i;
                count++;
            }
        }
        return count;
    }
};