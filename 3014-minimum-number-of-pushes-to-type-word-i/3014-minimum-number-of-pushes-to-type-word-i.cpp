class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        int i=1;
        while(n>0){
            if(n>8){
                n=n-8;
                ans+=8*i;
                i++;
            }else{
                ans+=n*i;

                n=0;
            }

        }
        return ans;
    }
};