class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }

        std::unordered_map<int, int> countNums;

        for (size_t i = 0; i < nums.size(); i++) {
            if (countNums.find(nums[i]) != countNums.end()) {
                return true;
            }
            countNums[nums[i]] = 1;
        }
        return false;

        
    }
};