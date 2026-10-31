class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned = "";

        for (char ch : s) {
            if (ch != '-') {
                cleaned += toupper(ch);
            }
        }

        string result = "";
        int count = 0;

        for (int i = cleaned.length() - 1; i >= 0; i--) {
            result += cleaned[i];
            count++;

            if (count == k && i != 0) {
                result += "-";
                count = 0;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};