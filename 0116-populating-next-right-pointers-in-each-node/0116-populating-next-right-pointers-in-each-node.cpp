/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        q.push(new Node(1001));
        while(q.size() && q.front()->val <=1000){
            Node* t = q.front();
            if(t->left) q.push(t->left);
            if(t->right)q.push(t->right);
            q.pop();
            Node* n = q.front();
            if(n->val>1000){
                q.pop();
                q.push(new Node(1001));
                continue;
            }
            t->next = n;
        }
        return root;
    }
};