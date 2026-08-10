/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define null nullptr
class Solution {
public:
    TreeNode* ans = null;
    int fun(TreeNode* r, TreeNode* p, TreeNode* q){
        if(r == null) return 0;
        int left = fun(r->left,p,q);
        int right = fun(r->right,p,q);
        int self = 0;
        if(r->val == p->val || r->val == q->val) self = 1;
        int total = left + right + self;
        if(total == 2 && ans == null){
            ans = r;
        }
        return total;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       int val = fun(root,p,q);
        return ans;
    }
};