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
        if(root->left == NULL and root->right == NULL){
            sum = max(sum, root->val);
            return root->val;
        }
            
        int a = util(root->left, sum);
        int b = util(root->right, sum);

        sum = max(max(sum, max(root->val, root->val + a + b)), max(a, b) + root->val);
        return max(max(a, b) + root->val, root->val);
        // sum = max(sum, max(max(root->val + a, root->val + b), root->val+a+b));
        // cout << "sum : " << sum <<endl;
        // cout << "a : " << a <<endl;
        // cout << "b : " << b <<endl;
        // cout << "root->val : " << root->val <<endl; 
        // return sum;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int res = util(root, sum);
        return max(res, sum);
    }
};