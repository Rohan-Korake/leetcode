class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       std::sort(arr2.begin(), arr2.end());
        
        int distance_value = 0;
        
        for (int i = 0; i < arr1.size(); ++i) {
            bool isValid = true;
            
            for (int j = 0; j < arr2.size(); ++j) {
                if (std::abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false;
                    break; 
                }
            }
            
            if (isValid) {
                distance_value++;
            }
        }
        
        return distance_value;
    }
};