class Solution {
public:

 long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k--)
        {
            int x2 = pq.top();
            pq.pop();
            int x = sqrt(x2);
            pq.push(x);
        }
        long long ans = 0;
        while (pq.size())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};