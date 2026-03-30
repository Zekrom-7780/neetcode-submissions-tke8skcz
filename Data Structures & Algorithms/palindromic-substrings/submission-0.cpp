class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for (int i=0;i<n-1;i++){
            if (s[i]==s[i+1]){
                dp[i][i+1]=1;
            }
        }
        for (int length=3;length<=n;length++){
            for (int l=0;l<n-length+1;l++){
                int r=l+length-1;
                if (dp[l+1][r-1] && (s[l]==s[r])){
                    dp[l][r]=1;
                }
            }
        }
        int ans=0;
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (dp[i][j]==1) ans++;
            }
        }
        return ans;
    }
};
