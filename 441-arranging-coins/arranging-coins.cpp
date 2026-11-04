class Solution {
public:
    int arrangeCoins(int n) {
        long int rowCount = 0;
        long int coinCount = 0;

        while (n > coinCount) {
            rowCount++;
            coinCount += rowCount;
        }
        if (n == coinCount)
            return rowCount;
        return rowCount - 1;
    }
};