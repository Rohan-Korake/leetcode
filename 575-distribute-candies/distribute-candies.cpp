class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> types;
        int s=candyType.size();
        for(int i=0;i<s;i++)
        {
            types.insert(candyType[i]);
        }

        if(s/2<types.size())
        {
            return s/2;
        }
        return types.size();
    }
};