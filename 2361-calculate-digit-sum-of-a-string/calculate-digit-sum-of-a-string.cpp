
class Solution {
public:
    std::string digitSum(string s, int k) {
        while (s.length() > k) {
            string nextStr = "";
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                int end = min((int)s.length(), i + k);

                for (int j = i; j < end; j++) {
                    sum += s[j] - '0';
                }

                nextStr += to_string(sum);
            }

            s = nextStr;
        }

        return s;
    }
};