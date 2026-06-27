#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    void encode(TreeNode* root, string &s) {
        if(root == nullptr) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        encode(root->left, s);
        encode(root->right, s);
    }

    TreeNode* decode(string &s, int &i) {
        if(s[i] == 'N') {
            i += 2;
            return nullptr;
        }

        string num = "";

        while(s[i] != ',') {
            num += s[i];
            i++;
        }

        i++;

        TreeNode* root = new TreeNode(stoi(num));

        root->left = decode(s, i);
        root->right = decode(s, i);

        return root;
    }

    string serialize(TreeNode* root) {
        string s = "";
        encode(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return decode(data, i);
    }
};

TreeNode* buildTree(vector<int>& nodes) {
    if(nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if(i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void printLevelOrder(TreeNode* root) {
    if(root == nullptr) {
        cout << "Empty Tree" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nodes(n);
    for(int i=0; i<n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    Codec ser, deser;

    string data = ser.serialize(root);
    cout << "Serialized: " << data << endl;

    TreeNode* newRoot = deser.deserialize(data);

    cout << "Deserialized Tree (Level Order):" << endl;
    printLevelOrder(newRoot);
    return 0;
}