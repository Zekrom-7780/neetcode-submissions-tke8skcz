class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i=0;i<n;i++){
            dp[i][i]=nums[i];
            if (nums[i]>maxi){
                maxi=nums[i];
            }
        }
        for (int len=2;len<=n;len++){
            for (int l=0;l<n-len+1;l++){
                int r=l+len-1;
                dp[l][r]=dp[l][r-1]*nums[r];
                if (dp[l][r]>maxi){
                    maxi=dp[l][r];
                }
            }
        }
        return maxi;
    }
};
