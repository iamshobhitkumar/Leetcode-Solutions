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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int postStart, int postEnd, int inStart, int inEnd, unordered_map<int,int>& m){
        if(postStart > postEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int element = m[root->val];
        int n = element - inStart;
        root->left = solve(inorder, postorder, postStart,postStart+n-1,inStart, element-1,m);
        root->right = solve(inorder, postorder, postStart+n, postEnd-1,element+1, inEnd,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postStart = 0, postEnd = n-1, inStart = 0, inEnd = n-1;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        return solve(inorder, postorder, postStart, postEnd, inStart, inEnd, m);
    }
};