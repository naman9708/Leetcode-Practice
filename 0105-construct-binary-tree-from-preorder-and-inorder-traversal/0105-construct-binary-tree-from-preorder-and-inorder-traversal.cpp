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
    int search(vector<int>& inorder,int key,int l,int r){
        for(int i = l;i<=r;i++){
            if(inorder[i]==key)return i;
        }
        return -1;
    }
    TreeNode* bt(vector<int>& preorder, vector<int>& inorder,int& pi,int l,int r){
        if(l>r)return NULL;
        TreeNode* root = new TreeNode(preorder[pi]);
        pi++;
        int ind = search(inorder,preorder[pi-1],l,r);
        root->left = bt(preorder,inorder,pi,l,ind-1);
        root->right = bt(preorder,inorder,pi,ind + 1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pi = 0;
    
        return bt(preorder,inorder,pi,0,inorder.size()-1);
    }
};