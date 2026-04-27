class DSU {
    vector<int>parent,size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int i){
        if (parent[i]!=i){
            return find(parent[i]);
        }
        return parent[i];
    }

    void unite(int i, int j){
        int root_i=find(i);
        int root_j=find(j);

        if (root_i==root_j) return;

        if (size[root_i]<size[root_j]){
            parent[root_i]=root_j;
            size[root_j]+=size[root_i];
        }
        else {
            parent[root_j]=root_i;
            size[root_i]+=size[root_j];
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int components=n;
        for (auto itr:edges){
            int u=itr[0];
            int v=itr[1];
            if (dsu.find(u)!=dsu.find(v)){
                dsu.unite(u,v);
                components--;
            }
        }
        return components;
    }
};
