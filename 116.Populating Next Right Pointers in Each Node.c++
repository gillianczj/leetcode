class solution {
public:
    void connect(TreeLinkNode* root) {
        if(!root) {
            return;
        }
        TreeLinkNode* p = root;//the current parent node
        TreeLinkNode* firstNode = NULL;//first node of each level
        while(p) {
            if(!firstNode) {//if not initialized
                firstNode = p->left;
            }
            if(firstNode) {//after assignment
                p->left->next = p->right;
            }else {//this level in empty
                break;
            }
            if(p->next) {
                p->right->next = p->next->left;
                p = p->next;
                continue;
            }else {//go to next level
                p = firstNode;
                firstNode = NULL;
            }
        }
    }
};
