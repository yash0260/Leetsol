class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        mp[0] = 1;

        int sum = 0;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            
            sum += nums[i];

            int required = sum - k;

            if(mp.find(required) != mp.end()) {
                cnt += mp[required];
            }

            mp[sum]++;
        }

        return cnt;
    }
};