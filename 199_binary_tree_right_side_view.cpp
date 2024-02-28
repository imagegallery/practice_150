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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);
        
        res.push_back(root->val);
        
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            for(int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right){
                    if(flag == false){
                        flag = true;
                        res.push_back(temp->right->val);
                    }
                    q.push(temp->right);
                }
                if(temp->left){
                    if(flag == false){
                        res.push_back(temp->left->val);
                        flag = true;
                    }
                    q.push(temp->left);
                }
            }
        }
        return res;
    }
};