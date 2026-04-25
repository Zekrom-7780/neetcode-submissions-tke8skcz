class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis, int i, int j, int n, int m){
        vis[i][j]=1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for (int z=0;z<4;z++){
            int row=i+dx[z];
            int col=j+dy[z];
            if (row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1'
            && !vis[row][col]){
                vis[row][col]=1;
                dfs(grid,vis,row,col,n,m);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool> (m,0));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,vis,i,j,n,m);
                    ans++;
                }    
            }
        }
        return ans;
    }
};
