class Solution {
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]); 
        vector<int> predp(n,0);
        vector<int> sufdp(n,0);
        predp[0]=0;
        predp[1]=nums[0];
        for (int i=2;i<n;i++){
            predp[i]=max((predp[i-2]+nums[i-1]),predp[i-1]);
        }
        sufdp[0]=0;
        sufdp[1]=nums[1];
         for (int i=2;i<n;i++){
            sufdp[i]=max((sufdp[i-2]+nums[i]),sufdp[i-1]);
        }
        return max(predp[n-1],sufdp[n-1]);
    }
};
