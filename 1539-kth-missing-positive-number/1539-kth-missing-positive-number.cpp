class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int i=1;
        int j=0;
       while(k>0){
            if(j<n && arr[j]==i){
                j++;
                i++;
                continue;
            }else{
                k--;
                if(k==0) return i;
                i++;
            }
        }
        return 0;
    }
};