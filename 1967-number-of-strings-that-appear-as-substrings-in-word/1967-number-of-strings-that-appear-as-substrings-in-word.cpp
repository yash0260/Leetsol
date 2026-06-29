class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        map<string,int>mpp;
        int l=word.size();
        for(int i=0;i<l;i++){
            string k="";
                for(int j=i;j<l;j++){
                    k+=word[j];
                    mpp[k]++;
            }
        }
int cnt=0;
int n=patterns.size();
for(int i=0;i<n;i++){
    if(mpp.find(patterns[i])!=mpp.end()){
        cnt++;
    }
}
return cnt;

    }
};