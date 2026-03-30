class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>> st;
        vector<int> ans(nums.size(),0);
        for (int i=0;i<nums.size();i++){
            while(!st.empty() && nums[i]>st.top().first){
                auto itr=st.top();
                st.pop();
                ans[itr.second]=i-itr.second;
            }
            st.push({nums[i],i});
        }
    return ans;
    }
};
