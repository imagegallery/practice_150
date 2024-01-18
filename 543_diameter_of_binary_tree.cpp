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
    int util(TreeNode* root, int &dia){
        if(root == NULL)
            return -1;
        if(root ->left == NULL and root->right == NULL)
            return 0;
    
        int a = util(root->left, dia);
        int b = util(root->right, dia);
    
        dia = max(dia, (a + 1) + (b + 1));
        //cout << "left " << a  << " right " << b << " root->val " << root->val << " sum " << sum << endl;
    
        return 1 + max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        util(root, dia);
        return dia;
    }
};