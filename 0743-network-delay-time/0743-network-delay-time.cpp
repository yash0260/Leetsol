class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        while(!q.empty()){
            auto it=q.top();
            int dist=it.first;
            int node=it.second;
            q.pop();
            for(auto iter:adj[node]){
             int adjnode=iter.first;
             int wt=iter.second;
             if(dist+wt<dis[adjnode]){
                dis[adjnode]=dist+wt;
                q.push({dis[adjnode],adjnode});
             }
            }
        }
        int res=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9)return -1;
            res=max(res,dis[i]);
        }
        return res;

    }
};