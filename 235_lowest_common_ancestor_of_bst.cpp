/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> path(TreeNode* root, TreeNode* p, vector<TreeNode*> &vec){
        if(p->val == root->val){
            vec.push_back(root);
            return vec;
        }
        vec.push_back(root);
        if(root->val > p->val)
            return path(root->left, p, vec);
        else
            return path(root->right, p, vec);
    }
    TreeNode* find_common(vector<TreeNode*> &a, vector<TreeNode*> &b){
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        for(; i < n && j < m; i++, j++){
            if(i == n - 1 and a[i]->val == b[j]->val)
                return a[i];
            if(j == m - 1 and a[i]->val == b[j]->val)
                return b[j];
            if(a[i]->val != b[j]->val){
                //cout << "not equal " <<endl;
                return a[i-1];
            }
                
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root == NULL)
        //     return NULL;
        
        // vector<TreeNode*> pathP;
        // vector<TreeNode*> pathQ;
        // //find path from root to P node and q node
        // path(root, p, pathP);
        // path(root, q, pathQ);
        // //find common element in both the path
        // TreeNode* n = find_common(pathP, pathQ);
        // return n;

        if(p->val < root->val and root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val and root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};