class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) {
            swap(start, destination);
        }

        int clockwiseDistance = 0;
        int total_distance = 0;

        for (int i = 0; i < distance.size(); i++) {
            total_distance += distance[i];
            if (i >= start && i < destination) {
                clockwiseDistance += distance[i];
            }
        }

        int counterClockwiseDistance = total_distance - clockwiseDistance;
        return min(clockwiseDistance, counterClockwiseDistance);
    }
};