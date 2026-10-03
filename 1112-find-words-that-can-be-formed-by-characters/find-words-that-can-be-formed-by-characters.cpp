class Solution {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::unordered_map<char, int> charCount;
        for (char c : chars) {
            charCount[c]++;
        }
        
        int totalLength = 0;
        
        for (const std::string& word : words) {
            std::unordered_map<char, int> tempCount = charCount;
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