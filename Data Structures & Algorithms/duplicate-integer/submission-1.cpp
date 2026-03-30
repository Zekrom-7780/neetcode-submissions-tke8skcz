class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for (int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        for (auto itr:umap){
            if (itr.second>1){
                return true;
            }
        }
        return false;
    }
};