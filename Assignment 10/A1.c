#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

int countLeafNodes(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int findMin(Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int height(Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void main() {
    Node* root = NULL;
    int values[] = {90, 20, 50, 120, 100, 40, 60, 80};
    int n = 7;
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));
    printf("Smallest value: %d\n", findMin(root));
    printf("Largest value: %d\n", findMax(root));
    printf("Height of tree: %d\n", height(root));
}
