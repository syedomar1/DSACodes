#include <stdio.h>
#include <stdlib.h>
struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
};
struct Node* root = NULL;
struct Node* createNode(int key) {
    struct Node* p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void Insert(int key) {
    struct Node* t = root;
    struct Node* r = NULL, *p;
    if (root == NULL) {
        p = createNode(key);
        root = p;
        return;
    }
    while (t != NULL) {
        r = t;
        if (key < t->data) {
            t = t->lchild;
        }
        else if (key > t->data) {
            t = t->rchild;
        }
        else {
            return;
        }
    }
    p = createNode(key);
    if (key < r->data) {
        r->lchild = p;
    }
    else {
        r->rchild = p;
    }
}

void Inorder(struct Node* p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Levelorder(struct Node* p) {
    struct Node* queue[100];
    int front = 0, rear = 0;
    printf("%d ", p->data);
    queue[rear++] = p;
    while (front != rear) {
        p = queue[front++];
        if (p->lchild) {
            printf("%d ", p->lchild->data);
            queue[rear++] = p->lchild;
        }
        if (p->rchild) {
            printf("%d ", p->rchild->data);
            queue[rear++] = p->rchild;
        }
    }
}

int Height(struct Node* p) {
    int l = 0;
    int r = 0;
    if (p == NULL) {
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r) {
        return l + 1;
    }
    else {
        return r + 1;
    }
}

int main() {
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);
    Insert(50);
    // Inorder(root);
    printf("\n");
    Levelorder(root);
    printf("\n");
    printf("Height: %d\n", Height(root));
    return 0;
}
