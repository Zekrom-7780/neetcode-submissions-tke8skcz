class Solution {
public:
    void recursion(vector<int>& nums, vector<int>& ans,
                   vector<vector<int>>& finalans,
                   int index, int target) {
        
        if (target == 0) {
            finalans.push_back(ans);
            return;
        }

        for (int j = index; j < nums.size(); j++) {
            
            // Skip duplicates
            if (j > index && nums[j] == nums[j - 1])
                continue;

            if (nums[j] > target)
                break;

            ans.push_back(nums[j]);
            recursion(nums, ans, finalans, j + 1, target - nums[j]);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Important
        vector<int> ans;
        vector<vector<int>> finalans;

        recursion(nums, ans, finalans, 0, target);
        return finalans;
    }
};
