class Solution {
public:
    int minOperations(string s) {
       int n = s.size();

        bool ok = true;
        for(int i = 1; i < n; i++){
            if(s[i] < s[i-1]){
                ok = false;
                break;
            }
        }

        if(ok) {return 0;}
        if(n <= 2) {return -1;}

        char mn = s[0], mx = s[0];

        for(int i = 0; i < n; i++){
            mn = min(mn, s[i]);
            mx = max(mx, s[i]);
        }

        if(s[0] == mn || s[n-1] == mx){
            return 1;
        }

        int cmn = 0, cmx = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == mn) {cmn++;}
            if(s[i] == mx) {cmx++;}
        }

        if(s[0] == mx && cmx == 1 && s[n-1] == mn && cmn == 1){
            return 3;
        }
        
        return 2; 
    }
};