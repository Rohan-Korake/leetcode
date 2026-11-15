class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long evenCount = 1;
        long long oddCount = 0;
        long long currentSum = 0;
        long long result = 0;
        int MOD = 1e9 + 7;

        for (int num : arr) {
            currentSum += num;

            if (currentSum % 2 != 0) {
                result = (result + evenCount) % MOD;
                oddCount++;
            } else {
                result = (result + oddCount) % MOD;
                evenCount++;
            }
        }
        return result;
    }
};