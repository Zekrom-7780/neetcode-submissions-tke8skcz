class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n,1);
        pref[0]=1;
        vector<int> suf(n,1);
        vector<int> res(n,1);
        suf[nums.size()-1]=1;
        for (int i=1;i<nums.size();i++){
            pref[i]=pref[i-1]*nums[i-1];
        }
        for (int i=nums.size()-2;i>=0;i--){
            suf[i]=suf[i+1]*nums[i+1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suf[i];
        }
        return res;
    }
};
