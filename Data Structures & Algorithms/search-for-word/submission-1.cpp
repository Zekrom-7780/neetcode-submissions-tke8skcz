class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y,
             string &word,
             int index,
             bool &finalans,
             vector<vector<bool>> &vis) {

        if (index == word.size()) {
            finalans = true;
            return;
        }

        if (x < 0 || y < 0 ||
            x >= board.size() || y >= board[0].size() ||
            vis[x][y] ||
            board[x][y] != word[index])
            return;

        vis[x][y] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            dfs(board,
                x + dx[i],
                y + dy[i],
                word,
                index + 1,
                finalans,
                vis);
        }

        vis[x][y] = false;  // backtrack
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();
        bool finalans = false;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, word, 0, finalans, vis);
                if (finalans) return true;  // early stop
            }
        }

        return false;
    }
};
