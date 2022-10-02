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
    int preid=0;
    TreeNode* buildmain(vector<int>& preorder, vector<int>& inorder,int st,int lst)
    {
        if(st>lst)
            return NULL;
        
        TreeNode* tnode=new TreeNode();
        tnode->val=preorder[preid++];
        tnode->left=NULL;
        tnode->right=NULL;
        
        if(st==lst)
            return tnode;
        
        int x=0;
        for(int i=0;i<inorder.size();i++)
        {
            if(tnode->val==inorder[i])
            {
                x=i;
                break;
            }
        }
        
        tnode->left = buildmain(preorder,inorder,st,x-1);
        tnode->right = buildmain(preorder,inorder,x+1,lst);
            
        return tnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildmain(preorder,inorder,0,preorder.size()-1);
    }
};