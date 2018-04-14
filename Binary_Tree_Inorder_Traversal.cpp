/* 给定一个二叉树，返回其中序遍历。 */

/* 例如： */
/* 给定二叉树 [1,null,2,3], */

/*    1 */
/*     \ */
/*      2 */
/*     / */
/*    3 */
/* 返回 [1,3,2]. */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        inorderTraversalre(root,res);
        return res;
    }
private:
    void inorderTraversalre(TreeNode* node,vector<int>& res){
        if(node){
            inorderTraversalre(node->left,res);
            res.push_back(node->val);
            inorderTraversalre(node->right,res);
        }
    }
};



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur || !stk.empty())
        {
            if(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else if(!stk.empty())
            {
                ret.push_back(stk.top()->val);
                cur = stk.top()->right;
                stk.pop();
            }
        }

        return ret;
    }
};
