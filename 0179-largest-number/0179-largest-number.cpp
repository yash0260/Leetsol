class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, string>> arr;

        // Store first digit and complete number
        for(int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            int first = s[0] - '0';

            arr.push_back({first, s});
        }

        // Manual sorting using nested loops
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                string a = arr[i].second;
                string b = arr[j].second;

                // Check which arrangement is larger
                if(a + b < b + a) {
                    swap(arr[i], arr[j]);
                }
            }
        }

        // If largest number is 0
        if(arr[0].second == "0") {
            return "0";
        }

        string ans = "";

        for(int i = 0; i < n; i++) {
            ans += arr[i].second;
        }

        return ans;
    }
};