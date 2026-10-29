class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> charRow = {
            {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1},
            {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2},
            {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3}
        };
        
        vector<string> result;
        
        for (const string& word : words) {
            if (word.empty()) continue;
            
            int row = charRow[tolower(word[0])];
            bool isValid = true;
            
            // Check if all other characters belong to the same row
            for (int i = 1; i < word.length(); ++i) {
                if (charRow[tolower(word[i])] != row) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};