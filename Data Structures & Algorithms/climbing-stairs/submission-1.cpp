class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n,0);
        dp[0]=1; //only 1 way of climbing stair
        dp[1]=2; //2 ways of climbing stairs
        for (int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
