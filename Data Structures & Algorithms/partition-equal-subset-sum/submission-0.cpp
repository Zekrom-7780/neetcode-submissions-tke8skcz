//Recursion

class Solution {
public:
    bool rec(int i, int sum, int totalSum, vector<int> &nums){
        if (i==nums.size()-1){
            if (sum==totalSum-sum){
                return true;
            }
            return false;
        }
        if (sum>totalSum-sum){
            return false;
        }
        return (rec(i+1,sum+nums[i],totalSum,nums) || rec(i+1,sum,totalSum,nums));
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        int sum=0;
        for (int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        return rec(0,sum,totalSum,nums);
    }
};
