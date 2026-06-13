class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res="";
        for(string &ak:words){
            int ans=0;
            for(char c:ak){
                ans+=weights[c-'a'];
            }
            int b=ans%26;
            char r='z'-b;
            res+=r;
        }
        return res;
    }
};