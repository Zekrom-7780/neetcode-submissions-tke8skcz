class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int low=0;
        int high=nums.size()-1;
        while (low<high){
            int sum=nums[low]+nums[high];
            if (sum>target){
                high--;
            }
            else if (sum<target){
                low++;
            }
            else  {
                ans={low+1,high+1};
                break;
            }
       }
       return ans; 
    }
};
