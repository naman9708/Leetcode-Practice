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
bool h(TreeNode* node,long n,long m){
    if(node == nullptr) return true;
    if(node->val <= n || node-> val >= m){
        return false;
    }
    return h(node->left,n,node->val) && h(node->right,node->val,m);
}
    bool isValidBST(TreeNode* root) {
        return h(root,LLONG_MIN, LLONG_MAX);
    }
};