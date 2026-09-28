class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need;
        for(char ch:t){
            need[ch]++;
        }
        int left=0;
        int right=0;
        int required=t.size();
        int minlen=INT_MAX;
        int start=0;
while(right<s.size()){
    if(need[s[right]]>0){
        required--;
    }
    need[s[right]]--;
    right++;
    while(required==0){
        if(right-left<minlen){
            minlen=right-left;
            start=left;
        }
        need[s[left]]++;
        if(need[s[left]]>0){
            required++;
        }
        left++;
    }
}
if(minlen==INT_MAX){
    return "";
}
return s.substr(start,minlen);
    }
};