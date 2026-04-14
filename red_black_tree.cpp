#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
        color = RED;
    }
};

class RBTree {
    Node *root;

    void rotateLeft(Node *&root, Node *&pt) {
        Node *pt_right = pt->right;
        pt->right = pt_right->left;

        if (pt->right != NULL)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_right;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;
        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rotateRight(Node *&root, Node *&pt) {
        Node *pt_left = pt->left;
        pt->left = pt_left->right;

        if (pt->left != NULL)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_left;
        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;
        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    void fixViolation(Node *&root, Node *&pt) {
        Node *parent_pt = NULL;
        Node *grand_parent_pt = NULL;

        while (pt != root && pt->color == RED && pt->parent->color == RED) {
            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            if (parent_pt == grand_parent_pt->left) {
                Node *uncle_pt = grand_parent_pt->right;

                if (uncle_pt != NULL && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    if (pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            } else {
                Node *uncle_pt = grand_parent_pt->left;

                if (uncle_pt != NULL && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    if (pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateLeft(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    }

    void BSTInsert(Node *&root, Node *&pt) {
        if (root == NULL)
            root = pt;

        else if (pt->data < root->data) {
            if (root->left == NULL) {
                root->left = pt;
                pt->parent = root;
            } else
                BSTInsert(root->left, pt);
        }

        else if (pt->data > root->data) {
            if (root->right == NULL) {
                root->right = pt;
                pt->parent = root;
            } else
                BSTInsert(root->right, pt);
        }
    }

    void inorderHelper(Node *root) {
        if (root == NULL)
            return;

        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }

public:
    RBTree() {
        root = NULL;
    }

    void insert(int data) {
        Node *pt = new Node(data);
        BSTInsert(root, pt);
        fixViolation(root, pt);
    }

    void inorder() {
        inorderHelper(root);
    }
};

int main() {
    RBTree tree;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        tree.insert(val);
    }

    cout << "Inorder Traversal:\n";
    tree.inorder();

    return 0;
}