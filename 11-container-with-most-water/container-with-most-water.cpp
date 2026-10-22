class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftBar = 0, rightBar = height.size() - 1, maxArea = 0;
        int currentArea = 0, totalWidth = 0, totalHeight = 0;

        while (leftBar < rightBar) {
            totalWidth = rightBar - leftBar;
            totalHeight = min(height[leftBar], height[rightBar]);
            currentArea = totalWidth * totalHeight;
            maxArea = max(currentArea, maxArea);

            if (height[leftBar] < height[rightBar]) {
                leftBar++;
            } else {
                rightBar--;
            }
        }
        return maxArea;
    }
};