#include <iostream>
#include <fstream>
using namespace std;

struct TreeNode {
    explicit TreeNode(int key) {
        this->key = key;
    }

    int key;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class BinTree {
public:
    explicit BinTree() {
        root = nullptr;
    }

    void Insert(int a) {
        TreeNode **c = &root;
        while (*c) {
            TreeNode &n = **c;
            if (a < n.key) {
                c = &n.left;
            } else if (a > n.key) {
                c = &n.right;
            } else {
                return;
            }
        }
        *c = new TreeNode(a);
    }

    TreeNode *root;
};

void Travel(TreeNode *v, std::ofstream &out) {
    if (v) {
        out << v->key << '\n';
        Travel(v->left, out);
        Travel(v->right, out);
    }
}

int main() {
    ifstream in("input.txt");
    int a;
    BinTree tree;
    while (in >> a) {
        tree.Insert(a);
    }
    in.close();
    ofstream out("output.txt");
    Travel(tree.root, out);
    out.close();
}