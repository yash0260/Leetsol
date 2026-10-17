class Solution {
public:
bool ispallindrome(string a){
    int i=0;
    int j=a.size()-1;
    while(i<=j){
        if(a[i]==a[j]){
            i++;
            j--;
        }else{
            return 0;
        }
    }
    return 1;
}
    int countSubstrings(string s) {
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            string k="";
            for(int j=i;j<n;j++){
            k+=s[j];
            if(ispallindrome(k))cnt++;
            }
            k="";
        }
        return cnt;
    }
};