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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int,int>& m){
        if(preStart>preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int element = m[root->val];
        int n = element - inStart;
        root->left = solve(preorder, inorder, preStart+1,preStart+n,inStart,element-1,m);
        root->right = solve(preorder,inorder, preStart+n+1,preEnd,element+1,inEnd,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preStart = 0, inStart = 0, preEnd = n-1, inEnd = n-1;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        return solve(preorder, inorder, preStart, preEnd, inStart, inEnd, m);
    }
};