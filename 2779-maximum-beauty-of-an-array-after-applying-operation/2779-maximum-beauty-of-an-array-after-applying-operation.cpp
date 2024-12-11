class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> freq;

    for (int num : nums) {
        freq[num - k]++;
        freq[num + k + 1]--;
    }

    int maxBeauty = 0, currentCount = 0;
    for (auto& [key, value] : freq) {
        currentCount += value;
        maxBeauty = max(maxBeauty, currentCount);
    }
        return maxBeauty;
}
};