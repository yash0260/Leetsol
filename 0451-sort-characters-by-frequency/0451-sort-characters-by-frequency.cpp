class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char c:s){
            freq[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &it:freq){
            pq.push({it.second,it.first});
        }
        string result="";
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
for(int i=0;i<top.first;i++){
    result += top.second;
}
        }
        return result;
    }
};