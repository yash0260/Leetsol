class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1000000007;

        for (auto &q : queries) {
            int l = q[0], r = q[1], step = q[2], mul = q[3];
            for (int idx = l; idx <= r; idx += step) {
                nums[idx] = (1LL *nums[idx] * mul) % MOD;
            }
        }

        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        cout<<ans<<endl;
        return ans;
    }
};