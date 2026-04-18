class Solution {
public:
    int mirrorDistance(int n) {
        string k=to_string(n);
        string j="";
        for(int i=k.size()-1;i>=0;i--){
j+=k[i];
        }
        int p=stoi(j);
        int ans=abs(p-n);
      return ans;
    }
};