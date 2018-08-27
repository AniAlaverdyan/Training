#include <iostream>

struct node {
    int number;
    struct node *left, *right; 
};

void preorder(struct node *node) {
    if (node == NULL) return;
    std::cout << node -> number << " ";
    preorder(node -> left);
    preorder(node -> right);
}

struct node *createNode(int tree_member) {
    node *temp = new node;
    temp -> number = tree_member;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}


int main()
{
    struct node *root = createNode(1);
    root -> left = createNode(2);
    root -> right = createNode(3);
    root -> left -> left = createNode(4);
    root -> left -> right = createNode(5);
    root -> right -> left = createNode(6); 
    preorder(root);
    return 0;
}
