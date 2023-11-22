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

void postOrder(struct Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n",root->data);
    }
}

int count (struct Node *root){
    if(root){
        return count(root->left) + count(root->right) + 1;
    }
    else{
        return 0;
    }
}

int height(struct Node *root){
    int x= 0, y=0;
    if (root==0)
    {
        return 0;
    }
    x=height(root->left);
    y=height(root->right);
    return x>y?x+1: y+1;
/*    if (x>y)
    {
        return x+1;
    }
    else{
        return y+1;
    }*/
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
    postOrder(p);
    printf("Count: %d\n",count(p));
    printf("Height: %d\n",height(p));
    return 0;
}