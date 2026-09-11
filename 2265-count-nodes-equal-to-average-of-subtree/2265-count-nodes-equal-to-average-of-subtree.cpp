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
int ans  = 0;
pair<int,int> dfs(TreeNode* root){
    if(root==NULL)return{0,0};
    
    auto l = dfs(root->right);
    auto r = dfs(root->left);

    int sum = root->val+ l.first + r.first;
    int cnt = 1 + r.second + l.second;

    if(sum/cnt == root->val)ans++;

    return {sum,cnt};

}
    int averageOfSubtree(TreeNode* root) {
        dfs(root);

        return ans;
    }
};