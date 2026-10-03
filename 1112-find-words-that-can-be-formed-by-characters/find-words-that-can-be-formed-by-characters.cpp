class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charCount;
        for (char c : chars) {
            charCount[c]++;
        }
        
        int totalLength = 0;
        
        for (const string& word : words) {
            unordered_map<char, int> tempCount = charCount;
            bool canForm = true;
            
            for (char c : word) {
                if (tempCount[c] > 0) {
                    tempCount[c]--;
                } else {
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                totalLength += word.length();
            }
        }
        
        return totalLength;
    }
};