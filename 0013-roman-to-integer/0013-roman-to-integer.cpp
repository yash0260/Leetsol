class Solution {
public:

    int check(char a){
        if(a=='I') return 1;
        if(a=='V') return 5;
        if(a=='X') return 10;
        if(a=='L') return 50;
        if(a=='C') return 100;
        if(a=='D') return 500;
        return 1000; // M
    }

    int romanToInt(string s) {

        int ans = 0;
        int prev = 0;

        for(int i = s.size()-1; i >= 0; i--) {

            int curr = check(s[i]);

            if(curr < prev)
                ans -= curr;
            else
                ans += curr;

            prev = curr;
        }

        return ans;
    }
};