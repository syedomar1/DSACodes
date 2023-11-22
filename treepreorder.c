#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create(int x)
{
    struct Node *n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void preOrder(struct Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *p = create(4);
    struct Node *p1 = create(1);
    struct Node *p2 = create(6);
    struct Node *p3 = create(5);
    struct Node *p4 = create(2);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    preOrder(p);
    return 0;
}