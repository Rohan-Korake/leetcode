class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long costA = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        
        long long costB = 1LL * costBoth * std::max(need1, need2);
        
        int buyMin = std::min(need1, need2);
        long long costC =
            1LL * costBoth * buyMin + 
            1LL * (need1 - buyMin) * cost1 +
            1LL * (need2 - buyMin) * cost2;
            
        return std::min({costA, costB, costC});
    }
};