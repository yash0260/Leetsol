class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;

        // Store nums1 elements in map
        for (int num : nums1) {
            mp[num]++;
        }

        // Check nums2 elements
        for (int num : nums2) {
            if (mp.find(num) != mp.end()) {
                return num;
            }
        }

        return -1;
    }
};