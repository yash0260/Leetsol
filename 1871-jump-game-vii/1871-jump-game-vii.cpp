class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        int farthest = 0;

        while(!q.empty()) {

            int curr = q.front();
            q.pop();

            // Reached destination
            if(curr == n - 1) {
                return true;
            }

            int start = max(curr + minJump, farthest);
            int end = min(curr + maxJump, n - 1);

            for(int next = start; next <= end; next++) {

                if(s[next] == '0' && !visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }

            farthest = curr + maxJump + 1;
        }

        return false;
    }
};