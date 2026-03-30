//Recursion

class Solution {
public:
    bool rec(int i, int sum, int totalSum, vector<int> &nums,
    vector<vector<int>> &dp){
        if (i==nums.size()){
            return (sum==totalSum-sum);
        }
        if (dp[i][sum]!=-1){
        return dp[i][sum];
       }
       if (sum>totalSum-sum){
        return 0;
       }

        dp[i][sum]=rec(i+1,sum+nums[i],totalSum,nums,dp)|| rec(i+1,sum,totalSum,nums,dp);
        return dp[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        int sum=0;
        for (int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int> (totalSum+1,-1));
        return rec(0,sum,totalSum,nums,dp);
    }
};
