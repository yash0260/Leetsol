class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size();
        
        unordered_map<int,int> c1, c2, total;
        
        for(int x : nums1){
            c1[x]++;
            total[x]++;
        }
        
        for(int x : nums2){
            c2[x]++;
            total[x]++;
        }
        
        for(auto &p : total){
            if(p.second % 2 != 0)
                return -1;
        }
        
        int cost = 0;
        
        for(auto &p : total){
            int x = p.first;
            int diff = abs(c1[x] - c2[x]);
            cost += diff / 2;
        }
        
        return cost / 2;
    }
};