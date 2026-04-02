#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node* root = NULL;

node* create(int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, int val) {
    if (root == NULL)
        return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

node* findMin(node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

node* deleteNode(node* root, int val) {
    if (root == NULL)
        return NULL;
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                break;
            case 4:
                printf("Preorder: ");
                preorder(root);
                break;
            case 5:
                printf("Postorder: ");
                postorder(root);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
}
