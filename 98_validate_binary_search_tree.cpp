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
    bool bstUtil(TreeNode* root, TreeNode*& prev){
        if(root){
            if(!bstUtil(root->left, prev))
                return false;
            if(prev != NULL && root->val <= prev->val)
                return false;
            prev = root;
            return bstUtil(root->right, prev);
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        TreeNode* prev = NULL;
        return bstUtil(root, prev);
    }
};