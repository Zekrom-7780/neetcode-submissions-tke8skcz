class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxi=INT_MIN;
        int start=-1;
        for (int i=0;i<n;i++){
            dp[i][i]=1;
            maxi=max(1,maxi);
            start=0;
        }
        for (int i=0;i<n-1;i++){
            if (s[i]==s[i+1]){
                dp[i][i+1]=1;
                maxi=max(2,maxi);
                start=i;
            }
        }

        
 for (int len = 3; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (dp[l + 1][r - 1] && s[l] == s[r]) {
                    dp[l][r] = true;
                    if (len > maxi) {
                        start = l;
                        maxi = len;
                    }
                }
            }
        }

        return s.substr(start, maxi);
    }
};
