class solution {
public:
    void connect(TreeLinkNode* root) {
        if(!root) {
            return;
        }
        TreeLinkNode* p = root;
        TreeLinkNode* first = NULL;
        TreeLinkNode* last = NULL;
        while(p) {
            if(!first) {//there is no first node
                if(p->left) {
                    first = p->left;
                }else if(p->right) {
                    first = p->right;
                }
            }
            if(p->left) {//check left node
                if(last) {
                    last->next = p->left;
                }
                last = p->left;
            }
            if(p->right) {//check right node
                if(last) {
                    last->next = p->right;
                }
                last = p->right;
            }
            if(p->next) {
                p = p->next;
            }else {//go to next level
                p = first;
                first = NULL;
                last = NULL;
            }
        }
    }
};
