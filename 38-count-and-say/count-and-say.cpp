class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string currentStr = "1";
        for (int i = 2; i <= n; ++i) {
            string nextStr = "";
            int len = currentStr.length();

            for (int j = 0; j < len; ++j) {
                int count = 1;
                while (j + 1 < len && currentStr[j] == currentStr[j + 1]) {
                    count++;
                    j++;
                }
                nextStr += to_string(count) + currentStr[j];
            }
            currentStr = nextStr;
        }
        return currentStr;
    }
};