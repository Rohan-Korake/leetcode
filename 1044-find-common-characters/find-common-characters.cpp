class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
     vector<int> min_freq(26, INT_MAX);
        for (const string& word : words) {
            vector<int> curr_freq(26, 0);
            for (char c : word) {
                curr_freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                min_freq[i] = min(min_freq[i], curr_freq[i]);
            }
        }
        
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (min_freq[i] > 0) {
                result.push_back(string(1, (char)(i + 'a')));
                min_freq[i]--;
            }
        }
        
        return result;
    }
};