class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;  // Stack to store digits

        // Iterate through each digit in num
        for (int i = 0; i < num.size(); i++) {
            char c = num[i];

            // Remove digits from stack if they are greater than current digit
            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                k--;
            }

            // Push current digit onto stack (avoid leading zeros)
            if (!st.empty() || c != '0') {
                st.push(c);
            }
        }

        // Remove extra digits from the top of the stack if k > 0
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // Construct the final number from stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse the result since stack stores in reverse order
        reverse(ans.begin(), ans.end());

        // If the result is empty, return "0"
        if (ans.empty()) {
    return "0";  // If ans is empty, return "0"
} 
return ans; 
    }
};