class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        k -= 1;
        int indx;
        string result;

        while (n != 0) {
            int num = n - 1;
            int fact = 1;
            for (int i = 1; i <= num; i++) {
                fact *= i;
            }

            indx = k / fact;
            result += to_string(nums[indx]); 

            for (int i = indx; i < n - 1; i++) {
                nums[i] = nums[i + 1];
            }
            n--;
            k = k % fact;
        }
        return result;
    }
};