#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
    int v;
    node* left, * right;

    static int height(node* root) {
        return root ? max(height(root->left), height(root->right)) + 1 : 0;
    }

    int balance_factor() {
        return height(left) - height(right);
    }
};

void left_rotate(node*& root) {
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;
}

void right_rotate(node*& root) {
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
}

void insert(node*& root, int v) {
    if (root == nullptr) {
        root = new node{ v };
        return;
    }

    if (v < root->v) {
        insert(root->left, v);
        if (root->balance_factor() == 2) {
            if (v < root->left->v) {
                right_rotate(root);
            }
            else {
                left_rotate(root->left);
                right_rotate(root);
            }
        }
    }
    else {
        insert(root->right, v);
        if (root->balance_factor() == -2) {
            if (v >= root->right->v) {
                left_rotate(root);
            }
            else {
                right_rotate(root->right);
                left_rotate(root);
            }
        }
    }
}

int main() {
    node* root = nullptr;

    int n, v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v);
        insert(root, v);
    }
    printf("%d\n", root->v);
}