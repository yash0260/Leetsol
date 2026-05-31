class Disjointset{
    public:
    vector<int>rank,par,size;
    Disjointset(int n){
        for(int i=0;i<=n;i++){
par.push_back(i);
rank.push_back(0);
size.push_back(1);
        }
    }
    int find(int n){
        if(par[n]==n){
            return n;
        }
        return par[n]=find(par[n]);
    }
    void unionbyrank(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(parA==parB)return ;
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if( rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }
};
class Solution {

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int cntextra=0;
        for(auto it:connections){
            int a=it[0];
            int b=it[1];
            if(ds.find(a)==ds.find(b)){
                cntextra++;
            }else{
                ds.unionbyrank(a,b);
            }

        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.par[i]==i)cnt++;
        }
        int ans=cnt-1;
        if(cntextra>=ans)return ans;
        return -1;
    }
};