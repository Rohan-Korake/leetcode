
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int totalPoisonedTime = 0;
        for (size_t i = 0; i < timeSeries.size() - 1; i++) {
            totalPoisonedTime += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        totalPoisonedTime += duration;
        
        return totalPoisonedTime;
    }
};