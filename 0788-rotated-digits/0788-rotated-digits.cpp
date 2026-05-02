class Solution {
    static bool isValid(int num) {
        bool res = false;
        while (num) {
            int d = num % 10;
            if (d == 3 || d == 4 || d == 7)
                return false;
            res |= d == 2 || d == 5 || d == 6 || d == 9;
            num /= 10;
        }
        return res;
    }

public:
    inline static const int lim = 10001;
    inline static int dp[lim];
    inline static bool init = []() {
        for (int i = 1; i < lim; i++)
            dp[i] = dp[i - 1] + isValid(i);
        return false;
    }();

    int rotatedDigits(int n) { return dp[n]; }
};