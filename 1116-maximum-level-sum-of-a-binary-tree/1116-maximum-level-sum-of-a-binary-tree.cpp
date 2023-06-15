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
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int maxSum = -1e9;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size()){
            TreeNode* node = q.front();
            int s = q.size();
            int sum = 0;
            for(int i=0;i<s;i++){
                cout<<"Processing "<<node->val<<endl;
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
                node = q.front();
            }
            level++;
            cout<<"Current level "<<level<<endl;
            if(sum > maxSum){
                maxSum = sum;
                ans = level;
            }
            cout<<"Current maxSum and ans: "<<maxSum<<" "<<ans<<endl;

        }
        return ans;
    }
};