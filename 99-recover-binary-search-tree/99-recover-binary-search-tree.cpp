class Solution {
private:
    void findViolations(TreeNode *root, TreeNode **prev, TreeNode **v1, TreeNode **v2) {
        if(!root)   return;
        
        findViolations(root->left, prev, v1, v2);
        
        if(root->val < (*prev)->val)
        {
            if(!*v1)
                *v1 = *prev;
            *v2 = root;
        }
        
        *prev = root;
        findViolations(root->right, prev, v1, v2);
    }
    
public:
    void recoverTree(TreeNode* root) {
        
        TreeNode *prev, *v1, *v2;
        v1 = v2 = NULL;
        prev = new TreeNode(INT_MIN);
        
        findViolations(root, &prev, &v1, &v2);
        
        v1->val ^= v2->val ^= v1->val ^= v2->val;
        
        return;
    }
};