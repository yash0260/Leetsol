class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       unordered_map<int,int>f;
       int n=fruits.size();
       int k=0;
       int len=0;

       int l=0;
       for(int r=0;r<n;r++){
        if(f[fruits[r]]==0){
k++;

        }
        f[fruits[r]]++;
while(k>2){
    f[fruits[l]]--;
    if(f[fruits[l]]==0){
        k--;
       
    }
     l++;

}
len=max(r-l+1,len);
       } 
       return len;
    }
};