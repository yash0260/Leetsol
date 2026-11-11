
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
      long long ans  = 1LL * cost1 * need1 + 1LL * cost2 * need2;

        long long ans2 = 1LL * costBoth * min(need1, need2);
        if (need1 > need2)
            ans2 += 1LL * cost1 * (need1 - need2);
        else
            ans2 += 1LL * cost2 * (need2 - need1);

        long long ans3 = 1LL * costBoth * max(need1, need2);

        return min({ans, ans2, ans3});
    }
};



