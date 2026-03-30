class Solution {
public:
    bool isValid(string s){
        if (s[0]=='0'){
            return false;
        }
        int a=stoi(s);
        if (a>26) return false;
        return true;
    }
    int numDecodings(string s) {
        int n=s.size();
        if (n==0) return 0;
        if (n==1) return isValid(s.substr(0,1));
        vector<int> dp(n,0);
        dp[0]=isValid(s.substr(0,1));
        dp[1]=isValid(s.substr(0,2))+ isValid(s.substr(0,1))*isValid(s.substr(1,1));
        for (int i=2;i<n;i++){
            int charval=isValid(s.substr(i,1));
            int strval=isValid(s.substr(i-1,2));
            dp[i]=(dp[i-1]*charval)+(dp[i-2]*strval);
        }
        return dp[n-1];
    }
};
