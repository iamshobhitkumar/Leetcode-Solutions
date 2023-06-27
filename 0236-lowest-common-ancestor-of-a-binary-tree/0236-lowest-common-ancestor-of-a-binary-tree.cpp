/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans, bool flag){
        if(!root) return false;
        bool left = false, right = false;
        if(!flag){
            left = solve(root->left, p,q,ans,flag);
            right = solve(root->right, p,q,ans,flag);
        }
        if(!flag && left && right){
            ans = root;
            flag = true;
        }
        if(left || right){
            if(root-> val == p->val || root->val == q->val){
                ans = root;
                flag = true;
            }
        }
        if(!flag && root->val == p->val || root->val == q->val) return true;
        return left || right;

            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        solve(root, p, q, ans, false);
        return ans;
    }
};