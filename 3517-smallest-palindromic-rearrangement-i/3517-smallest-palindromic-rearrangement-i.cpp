class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        string mid = "";

        // Build left half and middle character
        for (int i = 0; i < 26; i++) {

            // Add half of the occurrences to the left part
            for (int j = 0; j < freq[i] / 2; j++) {
                left += char('a' + i);
            }

            // If frequency is odd, this is the middle character
            if (freq[i] % 2 == 1) {
                mid += char('a' + i);
            }
        }

        // Right half is reverse of left half
        string right = left;
        reverse(right.begin(), right.end());

        // Form the palindrome
        return left + mid + right;
    }
};