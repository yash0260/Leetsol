class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int> freq;

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        vector<pair<int,int>> arr;

        for(auto& i : freq) {
            arr.push_back({i.second, i.first});
        }

        sort(arr.begin(), arr.end());

        vector<int> result;

        int m = arr.size();

        for(int i = m - 1; i >= m - k; i--) {
            result.push_back(arr[i].second);
        }

        return result;
    }
};