class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return "";
        int start=0,maxlength=0;
        for(int i=0;i<n;++i){
            int left=i,right=i;
            while(left>=0&& right<n && s[left] == s[right]){
                if(right-left+1>maxlength){
                    start=left;
                    maxlength =right-left+1;
                }
                --left;
                ++right;
            }
            left=i,right=i+1;
            while(left>=0 && right <n && s[left] == s[right] ){
                if (right - left + 1 > maxlength) {
                    start = left;
                    maxlength=right-left+1;
                }
                --left;
                ++right;
            }
        }
         return s.substr(start, maxlength);
    }
};