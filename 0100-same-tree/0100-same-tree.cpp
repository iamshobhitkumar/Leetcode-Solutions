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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(q1.size() && q2.size()){
            TreeNode* p1 = q1.front();
            TreeNode* p2 = q2.front();
            if(p1->val != p2->val)
                return false;
            if(p1->right || p1->left){
                if(p1->right)
                    q1.push(p1->right);
                else
                    q1.push(new TreeNode(1e6));
                if(p1->left)
                    q1.push(p1->left);
                else
                    q1.push(new TreeNode(1e6));
            }
            if(p2->right || p2->left){
                if(p2->right)
                    q2.push(p2->right);
                else
                    q2.push(new TreeNode(1e6));
                if(p2->left)
                    q2.push(p2->left);
                else
                    q2.push(new TreeNode(1e6));
            }
            q1.pop();
            q2.pop();
        }
        if(q1.size() || q2.size())
            return false;
        return true;
    }
};