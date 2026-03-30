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
    void SwapNodes(TreeNode* Curr){
       
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) return NULL;


        TreeNode* Curr=root;
        TreeNode* n_left=Curr->left;
        TreeNode* n_right=Curr->right;
        Curr->left=NULL;
        Curr->right=NULL;
        Curr->right=n_left;
        Curr->left=n_right;
        //while (root->left!=NULL && root->right !=NULL){
            invertTree(root->left);
            invertTree(root->right);
        //}
        
        return root;
    }
};
