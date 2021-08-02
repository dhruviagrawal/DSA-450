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
    int count = 0;
    int heigth(TreeNode*root)
    {
        if(!root)
            return 0;
        int l = heigth(root->left);
        int r = heigth(root->right);
        return max(l,r)+1;
    }
    void trav(TreeNode*root)
    {
        if(!root)return;
        trav(root->left);
        if(root->val%2==0)
            if(heigth(root)>1)
            {
                TreeNode*l = root->left, *r = root->right;
                if(l)
                {
                    if(l->left)
                        count+=l->left->val;
                    if(l->right)
                        count+=l->right->val;
                }
                 if(r)
                {
                    if(r->left)
                        count+=r->left->val;
                    if(r->right)
                        count+=r->right->val;
                }
            }
        trav(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        count = 0;
        trav(root);
        return count;
    }
};
