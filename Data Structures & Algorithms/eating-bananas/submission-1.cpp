class Solution {
public:
    bool isPossible (vector<int> &nums, int rate, int h){
        int counter=0;
        for (int i=0;i<nums.size();i++){
           counter+=(nums[i]+rate-1)/rate;
        }
        return (counter<=h);
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        if (h==nums.size()){
            return *max_element(nums.begin(),nums.end());
        }
        int low=1;
        int high= *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if (!isPossible(nums,mid,h)){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};
