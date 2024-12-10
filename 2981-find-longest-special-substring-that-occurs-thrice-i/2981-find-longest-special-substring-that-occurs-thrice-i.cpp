class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int maxLength = -1;
        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> countMap; 
            for (int i = 0; i <= n - len; ++i) {
                string sub = s.substr(i, len);
                if (isSpecial(sub)) {
                    countMap[sub]++;
                    if (countMap[sub] >= 3) {
                        maxLength = max(maxLength, len);
                    }
                }
            }
        }
return maxLength;
    }
private:
    // Helper function to check if a string is special
    bool isSpecial(const string& str) {
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] != str[0]) {
                return false;
            }
        }
        return true;
    }
};