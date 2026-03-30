class Solution {
public:
//min(arr[i,arr[j]])*j-i
    int maxArea(vector<int>& heights) {
        int j=heights.size()-1;
        int i=0;
        int finalans=INT_MIN;
        while (i<=j){
            int ans=min(heights[i],heights[j])*(j-i);
            finalans=max(finalans,ans);
            if (heights[i]<heights[j]){
                i++;
            }
            else j--;
        }
        return finalans;
    }
};
