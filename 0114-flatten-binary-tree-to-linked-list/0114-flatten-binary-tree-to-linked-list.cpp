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

    void solve(TreeNode* root){
        if(!root) return;
        if(root->left){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = NULL;
            root->right = left;
            while(left->right){
                left = left->right;
            }
            left->right = right;
        }
        solve(root->right);
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};