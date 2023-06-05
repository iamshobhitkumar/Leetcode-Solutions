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
    int getMinimumDifference(TreeNode* root) {
        int ans = 1e9;
        queue<TreeNode*> q;
        if(!root) return 0;
        vector<int> v;
        q.push(root);
        while(q.size()){
            TreeNode* f = q.front();
            v.push_back(f->val);
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            q.pop();
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            ans = min(ans,abs(v[i]-v[i+1]));
        }
        return ans;
    }
};