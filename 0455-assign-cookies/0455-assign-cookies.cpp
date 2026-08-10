class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        int n=g.size();
        int f=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=n-1 ;
        int j=f-1;
        while(i>=0 &&j>=0){
            if(g[i]<=s[j]){
                cnt++;
                i--;
                j--;
            }else{
                i--;
            }
        }

        return cnt;
            }
};