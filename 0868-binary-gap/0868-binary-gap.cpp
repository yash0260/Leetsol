class Solution {
public:
    int binaryGap(int n) {
        int a = 2;
        int len = 1;
        while (a < n) {
            if (a < n) {
                len++;
                a *= 2;
            }
        }
        int j = 1;
        string k = "";
        for (int i = 0; i < len; i++) {
            if ((n & j) == 0) {
                k += '0';
            } else {
                k += '1';
            }
            (j=j<<1);
        }
        reverse(k.begin(), k.end());
        int dist = 0;
        int prev = 0;
        int cnt = 0;
        for (int i = 0; i < k.size(); i++) {
            if (k[i] == '1') {
                cnt++;
            }
        }
        if (cnt <= 1) {
            return 0;
        }
        for (int i = 0; i < k.size(); i++) {
            if (k[i] == '1') {
                dist = max(dist, i - prev);
                prev = i;
            }
        }
        return dist;
    }
};