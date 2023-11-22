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
    p->lchild = NULL;
    p->rchild = NULL;
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

int main() {
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

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
