class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        int maxComponents = 1; // Start with the whole tree as one component

        // Build the adjacency list
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Helper DFS function
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long subtreeSum = values[node]; // Start with the value of the current node (use long long)

            for (int neighbor : graph[node]) {
                if (neighbor == parent) continue; // Skip the parent to avoid cycles
                long long childSum = dfs(neighbor, node);
                if (childSum % k == 0) {
                    maxComponents++; // Increment the component count if divisible by k
                } else {
                    subtreeSum += childSum; // Otherwise, add to the current subtree sum
                }
            }

            return subtreeSum;
        };

        // Start DFS from node 0
        dfs(0, -1);

        return maxComponents;
    }
};
