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
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root) return {};
        q.push(root);
        while(q.size()){
            TreeNode* f = q.front();
            int s = q.size();
            vector<int> v;
            for(int i=0;i<s;i++){
                v.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                q.pop();
                f = q.front();
            }
            ans.push_back(v);
        }
        return ans;
    }
};