class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int j=-1;
        string s="";
        for(int i=0;i<n;i++){
            int a=num[i]-'0';
            if(a%2!=0){
j=i;
            }
        }
        for(int i=0;i<=j;i++){
            s+=num[i];
        }
        return s;
    }
};