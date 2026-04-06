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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,unsigned long long>> mq;
        mq.push({root,0});
        while(!mq.empty()){
            int siz = mq.size();
            unsigned long long s = mq.front().second;
            unsigned long long e = mq.back().second;
            ans = max(ans,(int)(e-s+1));
            for(int i = 0;i<siz;i++){
                auto cur = mq.front();
                mq.pop();
                if(cur.first->left){
                    mq.push({cur.first->left,2*cur.second+1});
                }
                if(cur.first->right){
                    mq.push({cur.first->right,2*cur.second+2});
                }
            }

        }
        return ans;
    }
};