class Solution {
public:
    static const long long MOD = 1e9+7;
    int maxdepth=0;
    void dfs(int node, int parent ,int depth ,vector<vector<int>>&adj){
        maxdepth=max(maxdepth,depth);
        for(int child:adj[node]){
            if(child != parent){
                dfs(child,node,depth+1,adj);
            }
        }
    }
    long long power(long long a,long long b){
        long long res=1;
        while(b>0){
            if(b%2==1){
                res=(res*a)%MOD;
                }
                a=(a*a)%MOD;
                b=b/2;
            }
            return res;
        
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto &e :edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0,0,adj);
        return (int)power(2,maxdepth-1);
    }
};