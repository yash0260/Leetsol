class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        int n=g.size();
        int f=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<n&& j<f){
            if(g[i]<=s[j]){
                i++;
                j++;
                cnt=i;
            }else{
                j++;

            }

        }
        return cnt;
            }
};