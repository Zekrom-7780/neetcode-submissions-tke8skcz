class Solution {
public:
    /*area between 2 points i & j
    max(*max_element(heights[i],heights[j])*1,
    *min_element(heights[i],heights[j])* (j-i))
    */

    //brute
    int largestRectangleArea(vector<int>& nums) {
        int maxRect=0;
        for (int i=0;i<nums.size();i++){
            int bar=nums[i];
            int j=i+1;
            while(j<nums.size()){
                if (nums[j]>=nums[i]){
                    j++;
                }
                else break;
            }
            int s=i-1;
            while(s>=0){
                if (nums[s]>=nums[i]){
                    s--;
                }
                else break;
            }
            maxRect=max(maxRect,nums[i]*(j-s-1));
        }
        return maxRect;
    }
};
