class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
         unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        priority_queue<pair<char, int>> maxHeap;
        for (auto it : freq) {
            maxHeap.push({it.first, it.second}); 
        }

        string result = "";

        while (!maxHeap.empty()) {
            auto [char1, count1] = maxHeap.top();
            maxHeap.pop();
            int use_count = min(count1, repeatLimit);

            
            result.append(use_count, char1);

            
            count1 -= use_count;

           
            if (count1 > 0) {
                if (maxHeap.empty()) {
                    break;
                }

                
                auto [char2, count2] = maxHeap.top();
                maxHeap.pop();

              
                result.push_back(char2);

               
                count2--;

            
                if (count1 > 0) {
                    maxHeap.push({char1, count1});
                }
                if (count2 > 0) {
                    maxHeap.push({char2, count2});
                }
            }
        }

        return result; 
    }
};