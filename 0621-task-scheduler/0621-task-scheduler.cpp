class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    vector<int>freq(26,0) ;
    for(char task:tasks){
        freq[task-'A']++;
    }
    priority_queue<int>maxheap;
    for(int f:freq){
        if(f>0){
            maxheap.push(f);
        }
    }
    int time=0;
    while(!maxheap.empty()){
        vector<int>temp;
        for(int i=0;i<=n;i++){
            if(!maxheap.empty()){
                int f=maxheap.top();
                maxheap.pop();
                f--;
                if(f>0){
                    temp.push_back(f);
                }
                time++;
            }else{
                if(temp.empty()){
                    break;
                }
                time++;
            }
        }
        for(int f:temp){
            maxheap.push(f);
        }
    }
    return time;  
    }
};