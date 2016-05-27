class solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root) {
            return;
        }
        firstNode = NULL;
        secondNode = NULL;
        lastNode = new TreeNode(INT_MIN);
        traversal(root);
        swap(firstNode->val, secondNode->val);
    }
private:
    TreeNode* firstNode;
    TreeNode* secondNode;
    TreeNode* lastNode;
    
    void traversal(TreeNode* root) {//inorder traversal
        if(!root) {
            return;
        }
        traversal(root->left);
        if(!firstNode && root->val < lastNode->val) {//first wrong node
            firstNode = lastNode;
        }
        if(firstNode && root->val < lastNode->val) {//second wrong node
            secondNode = root;
        }
        traversal(root->right);
    }
};
