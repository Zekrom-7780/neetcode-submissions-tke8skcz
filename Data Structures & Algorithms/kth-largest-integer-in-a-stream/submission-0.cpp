class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>q;
int n;
    KthLargest(int k, vector<int>& nums) {
        n=k;
         for (int num : nums) {
            q.push(num);
            if (q.size() > n) {
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > n) {
            q.pop();
        }
        return q.top();
    }
};
