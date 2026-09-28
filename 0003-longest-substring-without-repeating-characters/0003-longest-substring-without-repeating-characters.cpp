class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
       int left=0;
       int ans=0;
       unordered_map<char,int>mpp;
       for(int right=0;right<n;right++){
while(mpp[s[right]]>=1){
mpp[s[left]]--;
left++;
       }
       mpp[s[right]]++;
       ans=max(ans,right-left+1);
    }
    return ans;
    }

};