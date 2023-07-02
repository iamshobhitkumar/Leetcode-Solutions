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

    TreeNode* solve(vector<int>& preorder, int start, int end){
        if(start>end) return NULL;
        TreeNode* root= new TreeNode(preorder[start]);
        int tend = start+1;
        while( tend <= end && preorder[tend] < preorder[start]) tend++;
        root->left = solve(preorder,start+1,tend-1);
        root->right = solve(preorder,tend,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size()-1);
    }
};