class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            int original = i;
            bool isValid = true;
            int num = i;

            while (num > 0) {
                int digit = num % 10;
                if (digit == 0 || original % digit != 0 ) {
                    isValid = false;
                    break;
                }
                num /= 10;
            }
            if (isValid) {
                result.push_back(i);
            }
        }
        return result;
    }
};