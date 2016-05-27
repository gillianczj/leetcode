class solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp) {
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
                if(!temp->left && !temp->right) {
                    ++level;
                    break;
                }
            }else {
                ++level;
                q.push(NULL);
            }
        }
        return level;
    }
};
