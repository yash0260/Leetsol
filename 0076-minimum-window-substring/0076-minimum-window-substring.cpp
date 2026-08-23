class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int>tMap,windowMap;
        for(char c:t)
        tMap[c]++;
        int required=tMap.size();
        int formed=0;
        int l=0,r=0;
        int minLen=INT_MAX;
        int start=0;
        while(r<s.size()){
            char c=s[r];
            windowMap[c]++;
            if(tMap.count(c) && windowMap[c]==tMap[c])
            formed++;
            while(l<=r && formed==required){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                char left=s[l];
                windowMap[left]--;
                 if (tMap.count(left) && windowMap[left] < tMap[left])
                    formed--;

                l++;

            }
            r++;

        }
        if(minLen==INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
};