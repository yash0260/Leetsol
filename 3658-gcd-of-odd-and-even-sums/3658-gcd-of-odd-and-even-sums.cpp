class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd=1;
        int oddsum=1;
        int even=2;
        int evensum=2;
        for(int i=0;i<n-1;i++){
            odd=odd+2;
            oddsum+=odd;
        }
        for(int i=0;i<n-1;i++){
even+=2;
evensum+=even;
        }
        int ans=gcd(oddsum,evensum);
        return ans;
    }
};