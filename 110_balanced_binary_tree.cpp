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
    int height(TreeNode* root, bool &balance){
        if(root == NULL)
            return 0;
        if(root ->left == NULL and root->right == NULL)
            return 1;
    
        int a = height(root->left, balance);
        int b = height(root->right, balance);
        if(abs(a-b) > 1)
            balance = false;
    
        return 1 + max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        bool balance = true;
        height(root, balance);
        return balance;
    }
};