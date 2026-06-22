class Solution {
public:
    int maxNumberOfBalloons(string text) {
       unordered_map<char,int>mpp;
       int n=text.size();
       string k="balloon";
       for(int i=0;i<k.size();i++){
        mpp[k[i]]=0;
       }
       for(int i=0;i<n;i++){
        
        mpp[text[i]]++;
       } 
       int ans=INT_MAX;
      for(int i=0;i<k.size();i++){
        if(k[i]=='b'){
ans=min(mpp['b'],ans);
        }
        if(k[i]=='a'){
            ans=min(mpp['a'],ans);
        }
        if(k[i]=='l'){
            ans=min(mpp['l']/2,ans);
        }
        if(k[i]=='o'){
            ans=min(mpp['o']/2,ans);
        }
        if(k[i]=='n'){
            ans=min(mpp['n'],ans);
        }
      }
       return ans;

    }
};