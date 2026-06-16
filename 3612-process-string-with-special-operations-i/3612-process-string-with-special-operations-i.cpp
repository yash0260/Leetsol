class Solution {
    void star(string &res,string &s){
res.pop_back();
    }
    void duplicate(string &res, string &s){
        res=res+res;
    }
    void rev( string &res,string &s){
        int n=res.size();
        string ans="";
        for(int i=n-1;i>=0;i--){
            ans+=res[i];
        }
        res=ans;
    }
public:
    string processStr(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='*' && res.size()>0){
                star(res,s);
            }else if(s[i]=='#' && res.size()>0){
                duplicate(res,s);
            } else if(s[i]=='%' && res.size()>0){
                rev(res,s);
            } else if(s[i]!='*' && s[i]!='#' && s[i]!='%'){
                res+=s[i];
            }
        }
        return res;
    }
};