#include <vector>
#include <algorithm>
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int totalPoisonedTime = 0;
        for (size_t i = 0; i < timeSeries.size() - 1; i++) {
            // Add either the full duration or the gap to the next attack, whichever is smaller
            totalPoisonedTime += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        // Always add the full duration for the very last attack
        totalPoisonedTime += duration;
        
        return totalPoisonedTime;
    }
};