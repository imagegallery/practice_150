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
    unordered_map<int, int> mp;
    int preIndex = 0;
    int find(vector<int> &in, int key){
        for(int i = 0; i < in.size(); i++)
            if(in[i] == key)
                return i;
        return 0;
    }
    TreeNode* arrayToTree(vector<int> &preorder, vector<int> &inorder, int st, int end){
        //static int index = 0;
        if(st > end)
            return NULL;
        
        TreeNode* root = new TreeNode( preorder[preIndex]);
        //int inIndex = find(inorder, preorder[preIndex]);
        int inIndex = mp[preorder[preIndex]];
        preIndex++;
        root->left = arrayToTree(preorder, inorder, st, inIndex -1);
        root->right = arrayToTree(preorder, inorder, inIndex+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        for(int i = 0; i <n; i++)
            mp[inorder[i]] = i;
        return arrayToTree(preorder, inorder, 0, n-1);
    }
};