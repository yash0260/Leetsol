class Solution {
    int f(string s){
        int n=s.size();
        int l=0;
        int ans=0;
        unordered_map<char,int>mpp;
     
        for(int r=0;r<n;r++){
mpp[s[r]]++;
while(mpp.size()>2){
    mpp[s[l]]--;
    if(mpp[s[l]]==0)mpp.erase(s[l]);
    l++;
}
ans+=r-l+1;

        }
        return ans;
    }
public:
    int numberOfSubstrings(string s) {
    int sum=0;
    int n=s.size();
        for(int i=0;i<n;i++){
        sum+=i+1;
    }
    return sum-f(s);
    }
};