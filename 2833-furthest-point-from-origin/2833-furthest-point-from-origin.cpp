class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int ans=0;
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='R' || moves[i] == '_')a+=1;
            else a-=1;
        }
        ans=max(abs(a),ans);
         for(int i=0;i<n;i++){
            if(moves[i]=='L' || moves[i] == '_')b+=1;
            else b-=1;
           
        }
         ans=max(abs(b),ans);
return ans;
    }
};