class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, int> lowerLast;
        map<char, int> upperFirst;

        int n = word.size();

        for (int i = 0; i < n; i++) {

            // lowercase
            if (word[i] >= 'a' && word[i] <= 'z') {
                lowerLast[word[i]] = i;
            }

            // uppercase
            else {
                char ch = word[i] + 32; // convert to lowercase

                // store first occurrence only
                if (upperFirst.find(ch) == upperFirst.end()) {
                    upperFirst[ch] = i;
                }
            }
        }

        int count = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {

            if (lowerLast.find(ch) != lowerLast.end() &&
                upperFirst.find(ch) != upperFirst.end()) {

                if (lowerLast[ch] < upperFirst[ch]) {
                    count++;
                }
            }
        }

        return count;
    }
};