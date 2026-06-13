class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      sort(strs.begin(),strs.end());
      string k=strs[0];
      string ans="";
      int n=strs.size();
      string last=strs[n-1];
      for(int i=0;i<last.size();i++){
        if(k[i]!=last[i]){
return k.substr(0,i);
        }
      }
      return "";
    }
};