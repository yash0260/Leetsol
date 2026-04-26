class Solution {
public:
    bool prime(int a){
     if(a<=1)return false;
        for(int i=2;i*i<=a;i++){
            if(a%i==0)return false;
        }
        return true;
    }
    int nextprime(int abb){
       if(abb < 2) return 2;

    int num = abb + 1;
    if(num % 2 == 0) num++;  

    while(!prime(num)) {
        num += 2;
    }
    return num;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                if(prime(nums[i])){
                    continue;
                }else{
                    int ak=nextprime(nums[i])-nums[i];
                    ans+=ak;
                }
            }else{
                if(prime(nums[i]) && nums[i]==1){
                    ans+=2;
                }
                else if(prime(nums[i]) && nums[i]==2){
                    ans+=2;
                }
                else if(prime(nums[i]) && nums[i]!=2  && nums[i]!=1){
                    ans+=1;
                }else{
                    continue;
                }
            }
        }
        return ans;
    }
};