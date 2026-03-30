class Solution {
public:
    void recursion(vector<int>& nums,vector<int>& ans, \
    vector<vector<int>> &finalans, int i){
        if (i==nums.size()){
            finalans.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        recursion(nums,ans,finalans,i+1);
        ans.pop_back();
        recursion(nums,ans,finalans,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalans;
        int i=0;
        recursion(nums,ans,finalans,i);
        return finalans;
    }
};
