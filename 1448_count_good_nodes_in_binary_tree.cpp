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
    void util(TreeNode* root, int maxSoFar, int &res){
        if(root == NULL)
            return;
        cout << maxSoFar <<endl;
        if(root->left and root->left->val >= maxSoFar){
            maxSoFar = max(root->left->val, maxSoFar);
            res++;
        }
        util(root->left, maxSoFar, res);
        //maxSoFar = root->val;
        if(root->right and root->right->val >= maxSoFar){
            maxSoFar = max(root->right->val, maxSoFar);
            res++;
        }
        util(root->right, maxSoFar, res);
        
        return;
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        //TreeNode* temp = root;
        int res = 1;
        
        util(root, root->val, res);
        //util(root->right, root->val, res);
        return res;
    }
};