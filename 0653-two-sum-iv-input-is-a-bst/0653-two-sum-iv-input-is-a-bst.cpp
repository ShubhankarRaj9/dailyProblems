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
    vector<int> res;
    void fn(TreeNode* r){
        if(r == nullptr) return;
        fn(r->left);
        res.push_back(r->val);
        fn(r->right);
        return ;
    }
    bool findTarget(TreeNode* root, int k) {
        fn(root);
        int i=0, j=res.size()-1;
        while(i<j){
            int sum = res[i] + res[j];
            if(sum == k)return true;
            else if(sum > k) j--;
            else i++;
        }
        return false;
    }
};