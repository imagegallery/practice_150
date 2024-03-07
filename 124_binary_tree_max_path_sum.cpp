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
    int util(TreeNode* root, int &sum){
        if(root == NULL)
            return 0;
            
        int a = max(util(root->left, sum), 0);
        int b = max(util(root->right, sum), 0);

        sum =max(sum, root->val + a+ b);
        return max(a, b) + root->val;
       
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int res = util(root, sum);
        return sum; //max(res, sum);
    }
};