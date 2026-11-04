class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        int k=strs[0].size();
        string ans="";
        for (int j = 0; j < k; j++) {

            for (int i = 0; i < n; i++) {

                if (j >= strs[i].size() ||
                    strs[0][j] != strs[i][j]) {
                    return ans;
                }
            }

            // All strings have the same character at index j
            ans += strs[0][j];
        }

        return ans;
    }
};