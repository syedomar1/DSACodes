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

struct Node *insert(struct Node *p,int key){
    struct Node *t;
    if (p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->left=t->right=NULL;
        return t;
    }
    if (key<p->data)    
    {
        p->left = insert(p->left,key);
    }
    else if (key>p->data)
    {
        p->right = insert(p->right,key);
    }
    return p;    
}

void inOrder(struct Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    struct Node *p = create(4);
    struct Node *p1 = create(1);
    struct Node *p2 = create(6);
    struct Node *p3 = create(5);
    struct Node *p4 = create(2);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    root=p;
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,25);
    
    inOrder(root);
    return 0;
}