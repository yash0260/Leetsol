class Solution {
public:
bool is(int i,vector<int>&vis,vector<int> &color ,vector<vector<int>>&graph){
     queue<pair<int, int>> q;
        q.push({i, 0});
        vis[i] = 1;
        color[i] = 0;
        while (!q.empty()) {
            int k = q.size();
            int node = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < k; i++) {
                for (auto it : graph[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;

                        if (col == 0) {
                            q.push({it, 1});
                            color[it] = 1;
                        } else {
                            q.push({it, 0});
                            color[it] = 0;
                        }
                    } else {
                        if (color[it] == col)
                            return false;
                    }
                }
            }
        }
return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> color(n, -1);
for(int i=0;i<n;i++){
    if(!vis[i]){
if(!is(i,vis,color,graph))return false;
    }
}
       return true;
    }
};