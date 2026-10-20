class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int current_len = 1, max_len = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                current_len++;
            } else {
                current_len = 1;
            }
            max_len = max(current_len, max_len);
        }
        return max_len;
    }
};