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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            double count = 0, sum = 0;
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* f = q.front();
                sum+= f->val;
                count++;
                q.pop();
                if(f->right) q.push(f->right);
                if(f->left) q.push(f->left);
            }
            v.push_back(sum/(double)count);
        }
        return v;
    }
};