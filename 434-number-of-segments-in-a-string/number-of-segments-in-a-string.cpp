class Solution {
public:
    int countSegments(string s) {
        stringstream str(s);
        string word;
        int counter=0;

        while(str >> word)
        {
            counter++;
        }
        return counter;
    }
};