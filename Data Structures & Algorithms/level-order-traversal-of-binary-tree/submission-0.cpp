/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root==NULL) return {};
        vector<vector<int>> finalans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> ans;
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front();
                ans.push_back(curr->val);
                q.pop();
                if (curr->left!=NULL){
                    q.push(curr->left);
                }
                if (curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            finalans.push_back(ans);
        }
        return finalans;
    }
};
