class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n,false);
        set<pair<int,int>> unmarked;
        for (int i =0;i<n;++i){
            unmarked.insert({nums[i],i});
        }
        long long score =0;
        while(!unmarked.empty()){
            auto it = unmarked.begin();
            int value = it->first;
            int index = it->second;
            score += value;
            vector<int> toErase;
            for (int i = max(0, index - 1); i <= min(n - 1, index + 1); ++i) {
                if (!marked[i]) {
                    marked[i] = true;
                    toErase.push_back(i);
                }
            }
             for (int i : toErase) {
                unmarked.erase({nums[i], i});
            }
        }

        return score;
    }
};
      