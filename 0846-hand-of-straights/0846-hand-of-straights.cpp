class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        unordered_map<int, int> freq;

        for (int card : hand) {
            freq[card]++;
        }

        sort(hand.begin(), hand.end());

        for (int card : hand) {

            // Already used up
            if (freq[card] == 0)
                continue;

            // Form a group starting from card
            for (int i = 0; i < groupSize; i++) {
                int curr = card + i;

                if (freq[curr] == 0)
                    return false;

                freq[curr]--;
            }
        }

        return true;
    }
};