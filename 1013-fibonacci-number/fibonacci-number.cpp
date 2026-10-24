class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int prev = 1, curr = 1, next = 0;
        int result = 0;

        for (int i = 0; i < n - 2; i++) {
            next = prev + curr;
            prev = curr;
            curr = next;
            result = next;
        }
        return next;
    }
};