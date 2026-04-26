class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //Check no cycles AND only 1 connected component
        if (edges.size()!=n-1) return false;
        vector<vector<int>> adj(n);
        for (auto itr:edges){
            int u=itr[0];
            int v=itr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        queue<int> q;
        int count=0;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for (auto itr:adj[node]){
                if (!vis[itr]){
                    vis[itr]=1;
                    q.push(itr);
                }
            }
        }
        for (auto itr:vis){
            if (itr!=1) return false;
        }
        return true;

    }
};
