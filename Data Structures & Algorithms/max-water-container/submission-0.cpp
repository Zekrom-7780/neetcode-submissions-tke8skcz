class Solution {
public:
    //area=(j-i)*min(arr[i],arr[j])
    int maxArea(vector<int>& nums) {
        int maxArea=0;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int area=(j-i)*min(nums[i],nums[j]);
            maxArea=max(area,maxArea);
            if (nums[i]<nums[j]){
                i++;
            }
            else j--;
        }
        return maxArea;
    }
};
