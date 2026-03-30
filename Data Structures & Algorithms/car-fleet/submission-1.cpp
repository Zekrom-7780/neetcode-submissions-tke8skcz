class Solution {
public:
    static bool SortVec(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first; 
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), SortVec);

        stack<double> st;

        for (int i = 0; i < cars.size(); i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (st.empty() || time >st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};
