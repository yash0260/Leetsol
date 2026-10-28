class Solution {
public:
    vector<vector<int>> generate(int n) {
    
        vector<vector<int>>ans;
        ans.push_back({1});
        n = n-1;
        int prev_idx = 0;
        while(n--){
            vector<int>temp;
            temp.push_back(1);
            for(int i=1;i<ans[prev_idx].size();i++){
                temp.push_back(ans[prev_idx][i]+ans[prev_idx][i-1]);
            }
            prev_idx++;
            temp.push_back(1);
            ans.push_back(temp);
        }
     return ans;
    }
};