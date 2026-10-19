class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int x:nums1){
            int i=0;
            while(nums2[i]!=x){
                i++;
            }
            int nge=-1;
            for (int j = i + 1; j < nums2.size(); j++) {
                if (nums2[j] > x) {
                    nge = nums2[j];
                    break;
                }
            }
            ans.push_back(nge);
        }

        return ans;
            }
};