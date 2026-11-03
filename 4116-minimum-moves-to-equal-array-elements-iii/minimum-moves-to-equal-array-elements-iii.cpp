class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxNum = nums[nums.size() - 1];
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] < maxNum) {
                counter++;
                nums[i]++;
            }
        }
        return counter;
    }
};