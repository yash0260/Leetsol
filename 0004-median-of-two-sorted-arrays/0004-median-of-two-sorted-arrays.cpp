class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        // Step 1: Merge arrays
        vector<int> merged;
        for (int i = 0; i < n; i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            merged.push_back(nums2[i]);
        }

        // Step 2: Sort merged array
        sort(merged.begin(), merged.end());

        // Step 3: Find median
        int total = merged.size();
        int mid = total / 2;

        if (total % 2 == 1) {
            return merged[mid];  // odd case
        } else {
            return (merged[mid - 1] + merged[mid]) / 2.0;  // even case
        }
    }
};