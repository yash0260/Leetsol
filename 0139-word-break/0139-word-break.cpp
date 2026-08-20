class Solution {
public:
bool solve(int index,string &s,vector<string> &wordDict,vector<int>&dp){
    if(index==s.size())return true;
    if(dp[index]!=-1)return dp[index];

    for(string word:wordDict){
        int len=word.size();
        if(index+len<=s.size() && s.substr(index,len)==word){
            if(solve(index+len,s,wordDict,dp))return dp[index]= true;
        }
    }
    return dp[index]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,wordDict,dp);
    }
};