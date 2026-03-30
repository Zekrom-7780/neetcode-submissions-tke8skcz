class Solution {
public:
    int minCostClimbingStairs(vector<int>& arr) {
        vector<int> cost(arr.size(), 0);
        cost[0] = arr[0];
        cost[1] = arr[1];
        for (int i = 2; i < arr.size(); i++) {
            cost[i] = min(cost[i - 1], cost[i - 2]) + arr[i];
        }
        return min(cost[arr.size() - 1], cost[arr.size() - 2]);
    }
};
