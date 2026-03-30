class Solution {
public:
    static bool sortvec(const vector<int>&a, const vector<int>&b){
        return a[2]<b[2];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>distances;
        for (auto itr:points){
            distances.push_back({itr[0],itr[1],(itr[0]*itr[0]+itr[1]*itr[1])});
        }
        sort(distances.begin(),distances.end(),sortvec);
        vector<vector<int>> ans;
        
          for (int i = 0; i < k; i++) {
            ans.push_back({distances[i][0], distances[i][1]});
        }
        return ans;
    }
};
