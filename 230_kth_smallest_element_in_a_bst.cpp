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
    void util1(TreeNode* root, vector<int> &inorder){
        if(root == NULL)
            return;
        util1(root->left, inorder);
        inorder.push_back(root->val);
        util1(root->right, inorder);
    }
    int util2(TreeNode* root, int &k){
        if(root == NULL)
            return -1;
        int left = util2(root->left, k);
        if(left != -1)
            return left;
        k--;
        if(k == 0)
            return root->val;
        int right = util2(root->right, k);
        if(right != -1)
            return right;
        return -1;
    }
    void util(TreeNode* root, int &k, int &res){
        if(root == NULL)
            return;
        util(root->left, k, res);
        k--;
        if(k == 0){
            res = root->val;
            return;
        }
        util(root->right, k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        util(root, k, res);
        return res;
        
        //return util2(root, k);

        //another sol
        // vector<int> inorder;
        // util(root, inorder);
        // return inorder[k-1];
    }
};