class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool present;
        for(int i=0;i<nums.size();i++)
        {
            present =false;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]==i)
                {
                    present=true;
                    continue;
                }
            }

            if(present==false)
            {
                return i;
                
            }
        }
        return nums.size();
    }
};