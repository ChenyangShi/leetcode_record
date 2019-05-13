#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node {
    int data;
    struct node* left; /*left是指针*/
    struct node* right;
} Node;

typedef struct {
    Node* root;
} Tree;

void insert(Tree* tree, int value) {
    Node* node = malloc(sizeof(Node));/*value打包成node*/
    node -> data = value;
    node -> left = NULL;
    node -> right = NULL;

    if (tree -> root == NULL) {
        tree -> root = value;
    }
    else {
        Node* temp = tree -> root;/*temp等于当前比较的根节点*/
        while (temp != NULL) {
            if (value < temp -> data) { /*left*/
                if (temp -> left == NULL) {
                    temp -> left = node;
                    return ; /*end*/
                }
                else {
                    temp = temp -> left; /*继续探索下一个左边*/
                }
            }
            else { /*right*/
                if (temp -> right == NULL) {
                    temp -> right = node;
                    return ; /*end*/
                }
                else {
                    temp = temp -> right;
                }
            }
        }
    }
}

void inorder(Node* node) {
    if (node != NULL){
        inorder(node -> left);
        printf("%d\n", node -> data);
        inorder(node -> right);
    }
}

int main() {
    int arr[7] = {6, 3, 8, 2, 5, 1, 7};
    Tree tree;
    tree.root = NULL;

    int i;
    for (i=0; i<7; i++) {
        insert(&tree, arr[i]);
    }

    inorder(tree.root);

    return 0;
}
