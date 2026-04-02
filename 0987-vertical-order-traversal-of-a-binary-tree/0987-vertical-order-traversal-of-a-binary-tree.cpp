class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int,int>>> tq;
        tq.push({root, {0, 0}});
        
        map<int, vector<pair<int,int>>> tmap;
        
        while (!tq.empty()) {
            auto cur = tq.front();
            tq.pop();
            
            TreeNode* node = cur.first;
            int col = cur.second.first;
            int row = cur.second.second;
            
            tmap[col].push_back({row, node->val});
            
            if (node->left)
                tq.push({node->left, {col - 1, row + 1}});
            
            if (node->right)
                tq.push({node->right, {col + 1, row + 1}});
        }
        
        vector<vector<int>> ans;
        
        for (auto &it : tmap) {
            auto vec = it.second;
            sort(vec.begin(), vec.end());
            
            vector<int> temp;
            for (auto &p : vec){
                temp.push_back(p.second);
            }            
            ans.push_back(temp);
        }
        
        return ans;
    }
};