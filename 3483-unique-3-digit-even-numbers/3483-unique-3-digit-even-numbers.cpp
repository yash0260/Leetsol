class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int>arr;
        int n=digits.size();
        if(n<3)return 0;
        for(int i=0;i<n;i++){
            if(digits[i]==0)continue;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && i!=k){
int a=digits[i]*100+digits[j]*10+digits[k];
if(a%2==0){
    arr.insert(a);
}
                    }
                }
            }
        }
        int ans=arr.size();
        return ans;
    }
};