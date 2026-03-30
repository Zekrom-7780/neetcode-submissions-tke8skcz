class Solution {
public:
    bool dfs(TreeNode* curr, TreeNode* p, TreeNode* q,TreeNode* &ans) {
        if (curr == NULL) return false;
        bool left = dfs(curr->left, p, q,ans);
        bool right = dfs(curr->right, p, q,ans);
        bool mid = (curr == p || curr == q);

        if (mid + left + right >= 2) {
            ans = curr;
        }
        return mid || left || right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        dfs(root, p, q,ans);
        return ans;
    }
};
