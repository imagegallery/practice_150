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
    // void util(TreeNode* root, unordered_map<int, int> mp, int &res){
    //     if(root == NULL)
    //         return;
    //     mp[root->val] ++;
    //     if(root->left == NULL && root->right == NULL){
    //         int count = 0;
    //         for(auto i : mp){
    //             if(i.second & 1)
    //                 count ++;
    //         }
    //         if(count <= 1)
    //             res++;
    //         return;
    //     }
    //     util(root->left,  mp, res);
    //     util(root->right, mp, res);
    //     return;
    // }
    //calculate atmost one odd value using bit operations.
    int util(TreeNode* root, int res){
        if(root == NULL)
            return 0;
        res ^= (1 << root->val);
        if(root->left == NULL && root->right == NULL){
            
            return ((res & (res-1)) == 0) ? 1 : 0;
        }
        int left = util(root->left, res);
        int right = util(root->right, res);
        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int res = 0;
        return util(root, res);
        
    }
};