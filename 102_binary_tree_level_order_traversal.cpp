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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL)
            return res;
        
        vector<int> level;
        queue<TreeNode* > q;
        TreeNode* dummy = new TreeNode(-2000);
        
        q.push(root);
        q.push(dummy);
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val == -2000){
                res.push_back(level);
                level.clear();
                if(q.size() > 0)
                    q.push(dummy);
            }else{
                level.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            //res.push_back(level);
        }
        q.pop();
        return res;
    }
};