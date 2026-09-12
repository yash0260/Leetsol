class Solution { 
    void expandFromCenter(string &s,int left,int right,int &start,int &maxLen){ 
        while (left >= 0 && right < s.size() && s[left] == s[right]) { 
            int len = right - left + 1; 
            if (len > maxLen) { 
                maxLen = len; 
                start = left; 
            } 
            left--; 
            right++; 
        }    
    } 
         
public: 
    string longestPalindrome(string s) { 
        int n=s.size(); 
        if(n==0)return ""; 
        int start=0,maxLen=1; 

        for(int i=0;i<n;i++){
            //odd center 
            expandFromCenter(s, i, i, start, maxLen);
            //even center 
            expandFromCenter(s, i, i + 1, start, maxLen); 
        } 

        return s.substr(start, maxLen); 
    } 
};