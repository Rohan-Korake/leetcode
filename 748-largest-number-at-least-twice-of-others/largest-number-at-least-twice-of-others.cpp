class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0; 

        int maxIndex = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == maxIndex) continue; 
            
            if (nums[maxIndex] < nums[i] * 2) {
                return -1;
            }
        }

        return maxIndex;
    }
};