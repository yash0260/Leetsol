class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>b;
        b=arr;
        int n=arr.size();
        sort(b.begin(),b.end());
        map<int,int>mpp;
       int k=1;
       int j=0;
       while(j<n){
        if(j==0){
            mpp[b[j]]=k;
            k++;
            j++;
        }else if(b[j]==b[j-1]){
            mpp[b[j]]=mpp[b[j-1]];
            j++;
        }else{
            mpp[b[j]]=k;
            j++;
            k++;
            
        }
        }
        for(int i=0;i<n;i++){
arr[i]=mpp[arr[i]];
        }
        return arr;

    }
};