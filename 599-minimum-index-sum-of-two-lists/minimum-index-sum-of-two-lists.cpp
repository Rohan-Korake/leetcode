class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        vector<string> result;
        int minSum = INT_MAX, currentSum = 0;

        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1[i] == list2[j]) {
                    currentSum = i + j;
                    if (currentSum < minSum) {
                        minSum = currentSum;
                        result.clear();
                        result.push_back(list1[i]);
                    } else if (currentSum == minSum) {
                        result.push_back(list1[i]);
                    }
                }
            }
        }

        return result;
    }
};