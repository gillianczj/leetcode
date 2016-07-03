class Codec {
public:
    string serialize(TreeNode* root) {
        vector<string> node;
        string tree;
        if(!root) {
            return tree;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            node.push_back(temp ? to_string(temp->val) + "," : "null,");//two cases
            if(temp) {//not nullptr has right and left child
                q.push_back(temp->left);//no matter is null or not
                q.push_back(temp->right);
            }
        }
        while(!node.empty() && node.back() == "null,") {
            node.pop_back();//elimimate the extra null
        }
        for(auto n : node) {
            tree += n;
        }
        return tree;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return NULL;
        }
        stringstream ss(data);
        string node;
        getline(ss, node, ',');
        TreeNode* root = new TreeNode(stoi(node));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(getline(ss, node, ',') && node != "null") {//node has left child
                temp->left = new TreeNode(stoi(node));
                q.push(temp->left);//non null can be in queue
            }
            if(getline(ss, node, ',') && node != "null") {
                temp->right = new TreeNode(stoi(node));
                q.push(temp->right);
            }
        }
        return root;
    }
};
