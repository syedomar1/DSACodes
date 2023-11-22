#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* lchild;
    int data;
    struct Node* rchild;
}*root=NULL;

struct Node* createNode(int key) {
    struct Node* p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void Insert(int key) {
    struct Node* t = root;
    struct Node* r=NULL,*p;

    if (root == NULL){
        p = createNode(key);
        root = p;
        return;
    }

    while(t != NULL){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }

    p = createNode(key);

    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
}

void Inorder(struct Node* p) {
    if (p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

struct Node* Search(int key) {
    struct Node* t = root;
    while (t != NULL){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return NULL;
}

struct Node *inorderPredecessor(struct Node* root){
    root = root->lchild;
    while (root->rchild!=NULL)
    {
        root=root->rchild;
    }
    return root;    
}

struct Node *deleteNode(struct Node *root, int val){
    struct Node *ipre;
    if (root==NULL)
    {
        return NULL;
    }
    if (root->lchild==NULL && root->rchild==NULL)
    {
        free(root);
        return NULL;  // return NULL as the node has been deleted
    }
    if (val<root->data)
    {
        root->lchild = deleteNode(root->lchild,val);  // update the left child
    }
    else if (val>root->data)
    {
        root->rchild = deleteNode(root->rchild,val);  // update the right child
    } 
    else{
        ipre = inorderPredecessor(root);
        root->data=ipre->data;
        root->lchild = deleteNode(root->lchild,ipre->data);  // update the left child
    }
    return root;   
}

int main() {
    struct Node *root = NULL;
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);
    p->lchild = p1;
    p->rchild = p2;
    p1->lchild = p3;
    p1->rchild = p4;
    root=p;
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);
    printf("\n");
    root = deleteNode(root,4);  // update root after deletion
    Inorder(root);
    printf("\n");

    struct Node* temp = Search(2);
    if (temp != NULL){
        printf("%d\n", temp->data);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
