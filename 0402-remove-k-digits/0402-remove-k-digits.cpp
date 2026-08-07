class Solution {
public:
    string removeKdigits(string s, int k) {
     stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > s[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        // If k is still left, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        if (res.empty())
            return "0";

        return res;
    }
};